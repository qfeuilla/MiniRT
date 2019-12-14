/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:42:53 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 16:56:21 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void			square_util(t_scene **scene, t_square **square)
{
	(*square)->next = NULL;
	if (!((*scene)->squares))
		(*scene)->squares = (*square);
	else
		ft_lstlast_square((*scene)->squares)->next = (*square);
}

t_vec3			manage_square(t_scene **scene, char *ln, int pl, int i)
{
	t_square	*square;
	int			error;

	error = 0;
	square = (t_square *)malloc(sizeof(t_square));
	square->position = get_vec3(ln, &i, pl, "position");
	if (vector_cmp(square->position, V_FALSE))
		return (V_FALSE);
	square->ori = get_vec3(ln, &i, pl, "rotation");
	if (vector_cmp(square->ori, V_FALSE) || !test_rot(square->ori))
		return (man_er(-3, '1', pl, "rotation"));
	square->size = get_each_digi_f(ln, i, &error);
	if (error)
		return (man_er(square->size, '1', pl, "size"));
	while (ln[i] == ' ')
		i++;
	if (ln[i += ft_int_len((int)square->size)] == '.')
		while (ft_isdigit(ln[++i]))
			;
	square->color = get_color(ln, &i, pl, "color");
	if (vector_cmp(square->color, V_FALSE))
		return (V_FALSE);
	square_util(scene, &square);
	return (test_endline(ln, i, pl));
}
