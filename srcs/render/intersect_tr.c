/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:17:28 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 18:28:30 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void	intersect_triangle(t_triangle *t, t_ray ray, t_hit *hit)
{
	t_vec3	e1;
	t_vec3	e2;
	t_vec3	tvec;
	t_vec3	pvec;
	t_vec3	qvec;

	e1 = sub_vecs(t->point2, t->point1);
	e2 = sub_vecs(t->point3, t->point1);
	if (dot(e1, (pvec = cross(ray.d, e2))) > -1e-8 && dot(e1, pvec) < 1e-8)
		return ;
	if (dot((tvec = sub_vecs(ray.o, t->point1)), pvec) * \
		(1 / dot(e1, pvec)) < 0 || dot(tvec, pvec) * (1 / dot(e1, pvec)) > 1)
		return ;
	qvec = cross(tvec, e1);
	if (dot(ray.d, qvec) * (1 / dot(e1, pvec)) < 0 || dot(tvec, pvec) * \
		(1 / dot(e1, pvec)) + dot(ray.d, qvec) * (1 / dot(e1, pvec)) > 1)
		return ;
	(*hit).t = dot(e2, qvec) * (1 / dot(e1, pvec));
	(*hit).triangle = t;
	qvec = cross(e1, e2);
	tvec = normalize(qvec);
	(*hit).normal = process_normal(ray, tvec);
}

t_hit	get_hit_triangle(t_scene *scene, t_ray ray, t_hit min_h)
{
	t_triangle	*triangle;
	t_hit		hit;

	triangle = scene->triangles;
	while (triangle)
	{
		init_hit(&hit);
		intersect_triangle(triangle, ray, &hit);
		if (hit.t < min_h.t && hit.t > 0)
			min_h = hit;
		triangle = triangle->next;
	}
	return (min_h);
}
