/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:05:30 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 15:53:05 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

t_vec3	calculate_rot(t_vec3 *c2, t_vec3 *c3, t_vec3 rot, t_vec3 to)
{
	t_vec3	c1;
	t_vec3	v;
	float	c;
	float	s;
	float	r;

	v = cross(to, rot);
	c = dot(rot, to);
	s = pow(magnitude(v), 2);
	r = ((1 - c) / s);
	c1 = vector(-r * (pow(v.y, 2) + pow(v.z, 2)) + 1, r * v.x * \
				v.y - v.z, r * v.x * v.z + v.y);
	(*c2) = vector(r * v.x * v.y + v.z, -r * (pow(v.x, 2) + \
					pow(v.z, 2)) + 1, r * v.y * v.x - v.x);
	(*c3) = vector(r * v.x * v.z - v.y, r * v.y * v.z - v.x, -r * \
					(pow(v.x, 2) + pow(v.y, 2)) + 1);
	return (c1);
}

t_vec3	apply_rot(t_vec3 pos, t_vec3 dir, t_vec3 rot)
{
	t_vec3	c1;
	t_vec3	c2;
	t_vec3	c3;
	t_vec3	prev;

	if (dir.x == 0 && dir.y < 0 && dir.z == 0)
		pos = vector(pos.x, pos.y, -pos.z);
	else if (!(dir.x == 0 && dir.y != 0 && dir.z == 0))
	{
		prev = pos;
		c1 = calculate_rot(&c2, &c3, rot, dir);
		pos = vector(dot(c1, prev), dot(c2, prev), dot(c3, prev));
	}
	return (pos);
}
