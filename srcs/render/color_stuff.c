/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:57:45 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 17:22:02 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

t_vec3		font_color(void)
{
	return (vector(10, 10, 10));
}

int			t_vec3_to_int(t_vec3 color, float intensitie)
{
	int col;

	col = (int)pow(256, 2) * (int)(intensitie * color.x);
	col += 256 * (int)(intensitie * color.y);
	col += (int)(intensitie * color.z);
	return (col);
}

t_vec3		c_to_vec(t_vec3 color)
{
	t_vec3 col;

	col.x = color.x / 255;
	col.y = color.y / 255;
	col.z = color.z / 255;
	return (col);
}

void		init_vec3(t_vec3 *vec)
{
	(*vec).x = 0;
	(*vec).y = 0;
	(*vec).z = 0;
}

float		maxi(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
