/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:36:09 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 16:50:15 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void			light_utils(t_scene **scene, t_light **light)
{
	(*light)->next = NULL;
	if (!((*scene)->lights))
		(*scene)->lights = (*light);
	else
		ft_lstlast_light((*scene)->lights)->next = (*light);
}

t_vec3			manage_light(t_scene **scene, char *ln, int pl)
{
	int			i;
	t_light		*light;
	int			error;

	i = 2;
	error = 0;
	light = (t_light *)malloc(sizeof(t_light));
	light->position = get_vec3(ln, &i, pl, "position");
	if (vector_cmp(light->position, V_FALSE))
		return (V_FALSE);
	light->ratio = get_each_digi_f(ln, i, &error);
	if (light->ratio > 1)
		return (man_er(-7, ' ', pl, "ratio"));
	if (error)
		return (man_er(light->ratio, '1', pl, "ratio"));
	while (ln[i] == ' ')
		i++;
	if (ln[i += ft_int_len((int)light->ratio)] == '.')
		while (ft_isdigit(ln[++i]))
			;
	light->color = get_color(ln, &i, pl, "color");
	if (vector_cmp(light->color, V_FALSE))
		return (V_FALSE);
	light_utils(scene, &light);
	return (test_endline(ln, i, pl));
}
