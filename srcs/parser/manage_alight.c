/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_alight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:29:46 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 16:37:09 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

t_vec3			manage_alight(t_scene **scene, char *ln, int pl)
{
	int			i;
	t_alight	*al;
	int			error;

	if ((*scene)->al)
		return (man_er(-6, 'l', pl, NULL));
	i = 2;
	error = 0;
	al = (t_alight *)malloc(sizeof(t_alight));
	al->ratio = get_each_digi_f(ln, i, &error);
	if (al->ratio > 1)
		return (man_er(-7, ' ', pl, "ratio"));
	if (error)
		return (man_er(al->ratio, '1', pl, "ratio"));
	while (ln[i] == ' ')
		i++;
	i++;
	if (ln[i] == '.')
		while (ft_isdigit(ln[++i]))
			;
	al->color = get_color(ln, &i, pl, "color");
	if (vector_cmp(al->color, V_FALSE))
		return (V_FALSE);
	(*scene)->al = al;
	return (test_endline(ln, i, pl));
}
