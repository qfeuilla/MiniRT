/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:41:04 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 13:50:31 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

t_vec3			manage_plane(t_scene **scene, char *ln, int pl)
{
	int			i;
	t_plane		*plane;

	i = 2;
	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->position = get_vec3(ln, &i, pl, "position");
	if (vector_cmp(plane->position, V_FALSE))
		return (V_FALSE);
	plane->orientation = get_vec3(ln, &i, pl, "rotation");
	if (vector_cmp(plane->orientation, V_FALSE))
		return (V_FALSE);
	if (!test_rot(plane->orientation))
		return (man_er(-3, '1', pl, "rotation"));
	plane->color = get_color(ln, &i, pl, "color");
	if (vector_cmp(plane->color, V_FALSE))
		return (V_FALSE);
	plane->next = NULL;
	if (!((*scene)->planes))
		(*scene)->planes = plane;
	else
		ft_lstlast_plane((*scene)->planes)->next = plane;
	return (test_endline(ln, i, pl));
}
