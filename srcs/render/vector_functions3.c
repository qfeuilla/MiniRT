/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:16:06 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 15:53:00 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

float	magnitude(t_vec3 a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
}

t_vec3	invert(t_vec3 vec)
{
	t_vec3 res;

	res.x = -1 * vec.x;
	res.y = -1 * vec.y;
	res.z = -1 * vec.z;
	return (res);
}

t_vec3	cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	cross;

	cross.x = v1.y * v2.z - v1.z * v2.y;
	cross.y = v1.z * v2.x - v1.x * v2.z;
	cross.z = v1.x * v2.y - v1.y * v2.x;
	return (cross);
}

t_vec3	cpy_vec3(t_vec3 src)
{
	t_vec3 dest;

	dest.x = src.x;
	dest.y = src.y;
	dest.z = src.z;
	return (dest);
}

t_vec3	clamp(t_vec3 vec)
{
	t_vec3 res;

	res.x = (vec.x > 1.0) ? 1.0 : vec.x;
	res.y = (vec.y > 1.0) ? 1.0 : vec.y;
	res.z = (vec.z > 1.0) ? 1.0 : vec.z;
	res.x = res.x * 255;
	res.y = res.y * 255;
	res.z = res.z * 255;
	return (res);
}
