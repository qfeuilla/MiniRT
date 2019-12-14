/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:13:30 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 18:27:33 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

t_vec3	process_normal(t_ray ray, t_vec3 normal)
{
	float	res;
	t_vec3	tmp;

	res = dot(ray.d, normal);
	if (res < 0)
		return (normal);
	tmp = invert(normal);
	return (tmp);
}
