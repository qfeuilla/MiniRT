/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:07:42 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 16:50:37 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void			sphere_utils(t_scene **scene, t_sphere **sphere)
{
	(*sphere)->next = NULL;
	if (!((*scene)->spheres))
		(*scene)->spheres = (*sphere);
	else
		ft_lstlast_sphere((*scene)->spheres)->next = (*sphere);
}

t_vec3			manage_sphere(t_scene **scene, char *ln, int pl)
{
	int			i;
	t_sphere	*sphere;
	int			error;

	i = 2;
	error = 0;
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->position = get_vec3(ln, &i, pl, "position");
	if (vector_cmp(sphere->position, V_FALSE))
		return (V_FALSE);
	sphere->radius = get_each_digi_f(ln, i, &error);
	if (error)
		return (man_er(sphere->radius, '1', pl, "radius"));
	sphere->radius = sphere->radius / 2;
	while (ln[i] == ' ')
		i++;
	i += ft_int_len((int)sphere->radius * 2);
	if (ln[i] == '.')
		while (ft_isdigit(ln[++i]))
			;
	sphere->color = get_color(ln, &i, pl, "color");
	if (vector_cmp(sphere->color, V_FALSE))
		return (V_FALSE);
	sphere_utils(scene, &sphere);
	return (test_endline(ln, i, pl));
}
