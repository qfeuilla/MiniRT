/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:39:03 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 22:12:20 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

float		inter_plane(t_ray ray, t_square *square)
{
	float	a;
	float	b;
	float	t;
	t_vec3	tmp;

	tmp = sub_vecs(ray.o, square->position);
	a = dot(tmp, square->ori);
	b = dot(ray.d, square->ori);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	t = -a / b;
	if (t < 0)
		return (0);
	return (t);
}

void		intersect_square(t_square *square, t_ray ray, t_hit *hit)
{
	float	t;
	float	a;
	t_vec3	p;
	t_vec3	data;

	if (!(t = inter_plane(ray, square)))
		return ;
	data = mult_vec_n(ray.d, t);
	p = add_vecs(ray.o, data);
	if (square->ori.x != 0 || square->ori.y == 0 \
		|| square->ori.z != 0)
		p = apply_rot(p, square->ori, vector(0, 1, 0));
	a = square->position.x - square->size / 2;
	data.x = square->position.x + square->size / 2;
	data.y = square->position.z - square->size / 2;
	data.z = square->position.z + square->size / 2;
	if (!((p.x >= a && p.x <= data.x) && \
		(p.z <= data.z && p.z >= data.y)))
		return ;
	(*hit).t = t;
	(*hit).square = square;
	(*hit).normal = process_normal(ray, square->ori);
}

t_hit		get_hit_square(t_scene *scene, t_ray ray, t_hit min_h)
{
	t_square	*square;
	t_hit		hit;

	square = scene->squares;
	while (square)
	{
		init_hit(&hit);
		intersect_square(square, ray, &hit);
		if (hit.t < min_h.t && hit.t > 0)
			min_h = hit;
		square = square->next;
	}
	return (min_h);
}
