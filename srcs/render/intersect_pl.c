/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:17:04 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 22:08:41 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void	intersect_plane(t_plane *plane, t_ray ray, t_hit *hit)
{
	float	a;
	float	b;
	float	t;
	t_vec3	tmp;

	tmp = sub_vecs(ray.o, plane->position);
	a = dot(tmp, plane->orientation);
	b = dot(ray.d, plane->orientation);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (init_hit(hit));
	t = -a / b;
	if (t < 0)
		return (init_hit(hit));
	(*hit).t = t;
	(*hit).plane = plane;
	(*hit).normal = process_normal(ray, plane->orientation);
}

t_hit	get_hit_plane(t_scene *scene, t_ray ray, t_hit min_h)
{
	t_plane		*plane;
	t_hit		hit;

	plane = scene->planes;
	while (plane)
	{
		init_hit(&hit);
		intersect_plane(plane, ray, &hit);
		if (hit.t < min_h.t && hit.t > 0)
			min_h = hit;
		plane = plane->next;
	}
	return (min_h);
}
