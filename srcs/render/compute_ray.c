/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:47:32 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/23 11:57:25 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

int		compute_ray(t_ray *ray, int x, int y, t_scene *s)
{
	float		w;
	float		h;
	float		fov;
	t_vec3		pixel;
	t_vec3		axis;

	axis = vector(0, 1, 0);
	fov = s->cameras->fov;
	w = s->screen->x;
	h = s->screen->y;
	pixel.x = (2 * (((float)x + 0.5) / w) - 1) * (w / h) * tan((fov / 2) * \
				(M_PI / 180));
	pixel.y = (1 - 2 * (((float)y + 0.5) / h)) * tan((fov / 2) * (M_PI / 180));
	pixel.z = 1;
	if (!(s->cameras->orientation.x == 0 && s->cameras->orientation.y > 0 && \
		s->cameras->orientation.z == 0))
		pixel = apply_rot(pixel, s->cameras->orientation, axis);
	(*ray).d = normalize(pixel);
	(*ray).o = s->cameras->position;
	return (1);
}
