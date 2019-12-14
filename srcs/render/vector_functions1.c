/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:08:15 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 15:53:03 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

t_vec3		div_vec_n(t_vec3 vec, float n)
{
	t_vec3 res;

	res.x = vec.x / n;
	res.y = vec.y / n;
	res.z = vec.z / n;
	return (res);
}

t_vec3		mult_vecs(t_vec3 vec, t_vec3 vec2)
{
	t_vec3 res;

	res.x = vec.x * vec2.x;
	res.y = vec.y * vec2.y;
	res.z = vec.z * vec2.z;
	return (res);
}

t_vec3		add_vecs(t_vec3 vec, t_vec3 vec2)
{
	t_vec3 res;

	res.x = vec.x + vec2.x;
	res.y = vec.y + vec2.y;
	res.z = vec.z + vec2.z;
	return (res);
}

t_vec3		vector(float x, float y, float z)
{
	t_vec3 new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

float		dist(t_vec3 a, t_vec3 b)
{
	float dist;

	dist = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + \
				pow(a.z - b.z, 2));
	return (dist);
}
