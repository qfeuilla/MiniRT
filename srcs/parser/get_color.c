/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:03:18 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 16:49:47 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

t_vec3		get_next_c_l(char *ln, int *i, int r, int pl)
{
	if (r > 255 || r < 0)
		return (man_er(-5, 'r', pl, "color"));
	while (ln[*i] == ' ')
		(*i)++;
	if (r == 0 && ln[*i] == '-')
		(*i)++;
	(*i) += ft_int_len((int)r);
	if (!(ln[(*i)] == ','))
		return (man_er(-4, 'r', pl, "color"));
	return (V_TRUE);
}

t_vec3		get_next_c(char *ln, int *i, int b, int pl)
{
	if (b > 255 || b < 0)
		return (man_er(-5, 'b', pl, "color"));
	while (ln[*i] == ' ')
		(*i)++;
	if (b == 0 && ln[*i] == '-')
		(*i)++;
	(*i) += ft_int_len((int)b);
	return (V_TRUE);
}

t_vec3		get_color(char *ln, int *i, int pl, char *type)
{
	int			r;
	int			g;
	int			b;
	t_vec3		color;
	int			error;

	error = 0;
	r = get_each_digi_i(ln, (*i), &error);
	if (error == 1)
		return (man_er(r, 'r', pl, type));
	if (vector_cmp(get_next_c_l(ln, i, r, pl), V_FALSE))
		return (V_FALSE);
	(*i)++;
	g = get_each_digi_i(ln, (*i), &error);
	if (error == 1)
		return (man_er(g, 'g', pl, type));
	if (vector_cmp(get_next_c_l(ln, i, g, pl), V_FALSE))
		return (V_FALSE);
	b = get_each_digi_i(ln, ++(*i), &error);
	if (error == 1)
		return (man_er(b, 'b', pl, type));
	if (vector_cmp(get_next_c(ln, i, b, pl), V_FALSE))
		return (V_FALSE);
	color = vector(r, g, b);
	return (color);
}
