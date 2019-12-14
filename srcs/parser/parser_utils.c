/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:59:45 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 16:59:22 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

t_vec3			rt_manager(t_scene **scene, char *type, char *ln, int pl)
{
	if (ft_strlen(ln) < 5)
		return (man_er(-1, '1', pl, type));
	if (!strcmp("R", type))
		return (manage_screen(scene, ln, pl));
	else if (!strcmp("A", type))
		return (manage_alight(scene, ln, pl));
	else if (!strcmp("c", type))
		return (manage_camera(scene, ln, pl));
	else if (!strcmp("l", type))
		return (manage_light(scene, ln, pl));
	else if (!strcmp("pl", type))
		return (manage_plane(scene, ln, pl));
	else if (!strcmp("sp", type))
		return (manage_sphere(scene, ln, pl));
	else if (!strcmp("sq", type))
		return (manage_square(scene, ln, pl, 2));
	else if (!strcmp("cy", type))
		return (manage_cylinder(scene, ln, pl));
	else if (!strcmp("tr", type))
		return (manage_triangle(scene, ln, pl));
	else
		return (man_er(-9, '0', pl, NULL));
}

char			*detach_type(char *ln, int pl)
{
	int		i;
	char	*type;
	char	*tmp;

	i = 0;
	while (ln[i] != '\0' && ln[i] != ' ')
		i++;
	if (ln[i] == ' ')
	{
		tmp = &ln[i];
		*tmp = '\0';
		type = ft_strdup(ln);
		*tmp = ' ';
		return (type);
	}
	else
	{
		man_er(-1, '1', pl, " ");
		return (NULL);
	}
}
