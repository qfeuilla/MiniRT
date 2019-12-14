/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:03:43 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/23 12:01:06 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void	intersect_sphere(t_sphere *sphere, t_ray ray, t_hit *hit)
{
	t_vec3		oc;
	float		a;
	float		b;
	float		discr;

	oc = sub_vecs(ray.o, sphere->position);
	a = dot(ray.d, ray.d);
	b = 2 * dot(oc, ray.d);
	discr = pow(b, 2) - 4 * a * (dot(oc, oc) - pow(sphere->radius, 2));
	if (discr < 0)
		return ;
	(*hit).t = (-b - sqrt(discr)) / (2 * a);
	if ((*hit).t < 0)
		(*hit).t = (-b + sqrt(discr)) / (2 * a);
	oc = mult_vec_n(ray.d, (*hit).t);
	(*hit).normal = add_vecs(ray.o, oc);
	oc = sub_vecs((*hit).normal, sphere->position);
	(*hit).sphere = sphere;
	(*hit).normal = normalize(oc);
}

t_hit	get_hit_sphere(t_scene *scene, t_ray ray, t_hit min_h)
{
	t_sphere	*sphere;
	t_hit		hit;

	sphere = scene->spheres;
	while (sphere)
	{
		init_hit(&hit);
		intersect_sphere(sphere, ray, &hit);
		if (hit.t < min_h.t && hit.t > 0)
			min_h = hit;
		sphere = sphere->next;
	}
	return (min_h);
}
