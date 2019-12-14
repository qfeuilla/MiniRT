/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_li_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:42:16 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 17:22:13 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void	free_lis(t_scene **s)
{
	t_light	*li;
	t_light	*next;

	li = (*s)->lights;
	while (li)
	{
		next = li->next;
		free(li);
		li = next;
	}
}

void	free_cams(t_scene **s)
{
	t_camera	*cam;
	t_camera	*next;

	cam = (*s)->cameras;
	while (cam)
	{
		next = cam->next;
		free(cam);
		cam = next;
	}
}
