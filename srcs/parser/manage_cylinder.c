/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:38:05 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 16:50:26 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void		cylinder_util(t_scene **scene, t_cylinder **cylinder)
{
	(*cylinder)->next = NULL;
	if (!((*scene)->cylinders))
		(*scene)->cylinders = (*cylinder);
	else
		ft_lstlast_cylinder((*scene)->cylinders)->next = (*cylinder);
}

t_vec3		get_each_cy(float *x, char *ln, int *i, int pl)
{
	int error;

	error = 0;
	(*x) = get_each_digi_f(ln, (*i), &error);
	if (error)
		return (man_er((*x), '1', pl, "diameter or height"));
	while (ln[*i] == ' ')
		(*i)++;
	if (ln[(*i) += ft_int_len((int)(*x))] == '.')
		while (ft_isdigit(ln[++(*i)]))
			;
	return (V_TRUE);
}

t_vec3		manage_cylinder(t_scene **scene, char *ln, int pl)
{
	int			i;
	t_cylinder	*cylinder;
	int			error;

	i = 2;
	error = 0;
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	cylinder->position = get_vec3(ln, &i, pl, "position");
	if (vector_cmp(cylinder->position, V_FALSE))
		return (V_FALSE);
	cylinder->orientation = get_vec3(ln, &i, pl, "rotation");
	if (vector_cmp(cylinder->orientation, V_FALSE))
		return (V_FALSE);
	if (!test_rot(cylinder->orientation))
		return (man_er(-3, '1', pl, "rotation"));
	cylinder->color = get_color(ln, &i, pl, "color");
	if (vector_cmp(cylinder->color, V_FALSE))
		return (V_FALSE);
	if (vector_cmp(get_each_cy(&(cylinder->diameter), ln, &i, pl), V_FALSE) || \
		vector_cmp(get_each_cy(&(cylinder->height), ln, &i, pl), V_FALSE))
		return (V_FALSE);
	cylinder_util(scene, &cylinder);
	return (test_endline(ln, i, pl));
}
