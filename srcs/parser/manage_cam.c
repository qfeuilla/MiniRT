/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:57:28 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 16:49:59 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void			cam_utils(t_scene **scene, t_camera **cam)
{
	(*cam)->next = NULL;
	(*cam)->prev = ft_lstlast_cam((*scene)->cameras);
	if (!((*scene)->cameras))
		(*scene)->cameras = (*cam);
	else
		ft_lstlast_cam((*scene)->cameras)->next = (*cam);
}

t_vec3			manage_camera(t_scene **scene, char *ln, int pl)
{
	int			i;
	t_camera	*cam;

	i = 2;
	cam = (t_camera *)malloc(sizeof(t_camera));
	cam->position = get_vec3(ln, &i, pl, "position");
	if (vector_cmp(cam->position, V_FALSE))
		return (V_FALSE);
	cam->orientation = get_vec3(ln, &i, pl, "rotation");
	if (vector_cmp(cam->orientation, V_FALSE))
		return (V_FALSE);
	if (!test_rot(cam->orientation))
		return (man_er(-3, '1', pl, "rotation"));
	while (ln[i] == ' ')
		i++;
	cam->fov = ft_atoi(&ln[i]);
	i += ft_int_len(cam->fov);
	cam_utils(scene, &cam);
	return (test_endline(ln, i, pl));
}
