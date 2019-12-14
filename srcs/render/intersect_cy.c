/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:42:15 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 18:28:42 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

t_vec3	g_normal;
float	g_t_min;
t_vec3	g_t;
t_vec3	g_b;

float	intersect_caps(t_ray ra, t_cylinder *cy, t_vec3 pos)
{
	t_vec3	tmp;
	float	a;
	float	b;
	float	t0;

	t0 = 0;
	tmp = sub_vecs(ra.o, pos);
	a = dot(tmp, cy->orientation);
	b = dot(ra.d, cy->orientation);
	if (!(b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0)))
		t0 = -a / b;
	return (t0);
}

float	calc_c(t_ray ra, t_cylinder *cy)
{
	return (dot(cross(sub_vecs(ra.o, g_b), sub_vecs(g_t, g_b)), \
		cross(sub_vecs(ra.o, g_b), sub_vecs(g_t, g_b))) - \
		((cy->diameter / 2) * (cy->diameter / 2) * dot(sub_vecs(g_t, g_b), \
		sub_vecs(g_t, g_b))));
}

void	infinite_cy(t_ray ra, t_cylinder *cy)
{
	float	t0;
	t_vec3	p;
	float	a;
	float	b;
	float	c;

	a = dot(cross(ra.d, sub_vecs(g_t, g_b)), cross(ra.d, sub_vecs(g_t, g_b)));
	b = 2 * dot(cross(ra.d, sub_vecs(g_t, g_b)), cross(sub_vecs(ra.o, g_b), \
				sub_vecs(g_t, g_b)));
	c = calc_c(ra, cy);
	if (pow(b, 2) - 4 * a * c > 0)
	{
		t0 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		if (t0 < 0)
			t0 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		p = add_vecs(ra.o, mult_vec_n(ra.d, t0));
		p = apply_rot(p, cy->orientation, vector(0, 1, 0));
		g_b = apply_rot(g_b, cy->orientation, vector(0, 1, 0));
		g_t = apply_rot(g_t, cy->orientation, vector(0, 1, 0));
		if (t0 < g_t_min && p.y >= g_b.y && p.y <= g_t.y && (g_t_min = t0))
		{
			p = apply_rot(p, vector(0, 1, 0), cy->orientation);
			g_normal = normalize(sub_vecs(p, cy->position));
		}
	}
}

void	intersect_cylinder(t_cylinder *cy, t_ray ra, t_hit *hit)
{
	float	t0;
	t_vec3	p;

	t0 = 0;
	g_t_min = INFINITY;
	g_b = sub_vecs(cy->position, mult_vec_n(normalize(cy->orientation), \
														cy->height / 2));
	g_t = add_vecs(cy->position, mult_vec_n(normalize(cy->orientation), \
														cy->height / 2));
	t0 = intersect_caps(ra, cy, g_t);
	p = add_vecs(ra.o, mult_vec_n(ra.d, t0));
	if (t0 > 0 && dist(p, g_t) <= cy->diameter / 2 && (g_t_min = t0))
		g_normal = process_normal(ra, cy->orientation);
	t0 = intersect_caps(ra, cy, g_b);
	p = add_vecs(ra.o, mult_vec_n(ra.d, t0));
	if (t0 > 0 && dist(p, g_b) <= cy->diameter / 2 && (g_t_min = t0))
		g_normal = process_normal(ra, cy->orientation);
	infinite_cy(ra, cy);
	if (!(g_t_min > 0 && g_t_min != INFINITY))
		return ;
	(*hit).t = g_t_min;
	(*hit).cylinder = cy;
	(*hit).normal = g_normal;
}

t_hit	get_hit_cylinder(t_scene *scene, t_ray ray, t_hit min_h)
{
	t_cylinder		*cylinder;
	t_hit			hit;

	cylinder = scene->cylinders;
	while (cylinder)
	{
		init_hit(&hit);
		intersect_cylinder(cylinder, ray, &hit);
		if (hit.t < min_h.t && hit.t > 0)
			min_h = hit;
		cylinder = cylinder->next;
	}
	return (min_h);
}
