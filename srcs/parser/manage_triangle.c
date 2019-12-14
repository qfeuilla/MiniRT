/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:56:04 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 15:35:05 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

t_vec3			manage_triangle(t_scene **scene, char *ln, int pl)
{
	int			i;
	t_triangle	*triangle;

	i = 2;
	triangle = (t_triangle *)malloc(sizeof(t_triangle));
	triangle->point1 = get_vec3(ln, &i, pl, "point1");
	if (vector_cmp(triangle->point1, V_FALSE))
		return (V_FALSE);
	triangle->point2 = get_vec3(ln, &i, pl, "point2");
	if (vector_cmp(triangle->point2, V_FALSE))
		return (V_FALSE);
	triangle->point3 = get_vec3(ln, &i, pl, "point3");
	if (vector_cmp(triangle->point3, V_FALSE))
		return (V_FALSE);
	triangle->color = get_color(ln, &i, pl, "color");
	if (vector_cmp(triangle->color, V_FALSE))
		return (V_FALSE);
	triangle->next = NULL;
	if (!((*scene)->triangles))
		(*scene)->triangles = triangle;
	else
		ft_lstlast_triangle((*scene)->triangles)->next = triangle;
	return (test_endline(ln, i, pl));
}
