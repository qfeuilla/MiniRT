/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:09:12 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 18:28:44 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void	init_hit(t_hit *hit)
{
	(*hit).normal = V_FALSE;
	(*hit).t = INFINITY;
	(*hit).sphere = NULL;
	(*hit).triangle = NULL;
	(*hit).square = NULL;
	(*hit).plane = NULL;
	(*hit).cylinder = NULL;
}

t_hit	get_hit(t_scene *scene, t_ray ray)
{
	t_hit min_h;

	init_hit(&min_h);
	min_h = get_hit_sphere(scene, ray, min_h);
	min_h = get_hit_plane(scene, ray, min_h);
	min_h = get_hit_square(scene, ray, min_h);
	min_h = get_hit_triangle(scene, ray, min_h);
	min_h = get_hit_cylinder(scene, ray, min_h);
	return (min_h);
}

t_vec3	get_hit_color(t_hit hit)
{
	t_vec3		hit_color;

	if (hit.cylinder)
		hit_color = hit.cylinder->color;
	else if (hit.square)
		hit_color = hit.square->color;
	else if (hit.triangle)
		hit_color = hit.triangle->color;
	else if (hit.plane)
		hit_color = hit.plane->color;
	else if (hit.sphere)
		hit_color = hit.sphere->color;
	else
		hit_color = V_FALSE;
	return (hit_color);
}
