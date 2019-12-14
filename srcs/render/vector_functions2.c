/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:14:47 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 15:53:02 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

float		dot(t_vec3 v1, t_vec3 v2)
{
	float x;

	x = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (x);
}

t_vec3		normalize(t_vec3 vec)
{
	t_vec3		res;
	double		l;
	double		invl;

	l = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
	invl = 1 / l;
	res = vector(vec.x * invl, vec.y * invl, vec.z * invl);
	return (res);
}

t_vec3		mult_vec_n(t_vec3 vec, float n)
{
	t_vec3 res;

	res.x = vec.x * n;
	res.y = vec.y * n;
	res.z = vec.z * n;
	return (res);
}

t_vec3		sub_vec_n(t_vec3 vec, float n)
{
	t_vec3 res;

	res.x = vec.x - n;
	res.y = vec.y - n;
	res.z = vec.z - n;
	return (res);
}

t_vec3		sub_vecs(t_vec3 vec, t_vec3 vec2)
{
	t_vec3 res;

	res.x = vec.x - vec2.x;
	res.y = vec.y - vec2.y;
	res.z = vec.z - vec2.z;
	return (res);
}
