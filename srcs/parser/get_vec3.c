/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:45:24 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 13:41:10 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void		get_next(char *ln, int *i, float x)
{
	while (ln[*i] == ' ')
		(*i)++;
	if (x < 1 && x > -1 && ln[*i] == '-')
		(*i)++;
	(*i) += ft_int_len((int)x);
	if (ln[(*i)] == '.')
		while (ft_isdigit(ln[++(*i)]))
			;
}

t_vec3		get_vec3(char *ln, int *i, int pl, char *type)
{
	float		x;
	float		y;
	float		z;
	int			error;

	error = 0;
	x = get_each_digi_f(ln, (*i), &error);
	if (error == 1)
		return (man_er(x, 'x', pl, type));
	get_next(ln, i, x);
	if (!(ln[(*i)] == ','))
		return (man_er(-4, 'x', pl, type));
	(*i)++;
	y = get_each_digi_f(ln, (*i), &error);
	if (error == 1)
		return (man_er(y, 'y', pl, type));
	get_next(ln, i, y);
	if (!(ln[(*i)] == ','))
		return (man_er(-4, 'y', pl, type));
	(*i)++;
	z = get_each_digi_f(ln, (*i), &error);
	if (error == 1)
		return (man_er(z, 'z', pl, type));
	get_next(ln, i, z);
	return (vector(x, y, z));
}
