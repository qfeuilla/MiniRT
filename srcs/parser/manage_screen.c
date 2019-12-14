/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:18:31 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 17:00:52 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

t_vec3			manage_screen(t_scene **scene, char *ln, int pl)
{
	int			i;
	t_screen	*screen;
	int			er;

	if ((*scene)->screen)
		return (man_er(-6, 's', pl, NULL));
	i = 2;
	er = 0;
	screen = (t_screen *)malloc(sizeof(t_screen));
	screen->x = get_each_digi_i(ln, i, &er);
	if (screen->x < 0)
		return (man_er(-2, 'x', pl, "of screen"));
	if (er)
		return (man_er(screen->x, '1', pl, "resox"));
	while (ln[i] == ' ')
		i++;
	screen->y = get_each_digi_i(ln, (i += ft_int_len(screen->x)), &er);
	if (screen->y < 0)
		return (man_er(-2, 'y', pl, "of screen"));
	if (er)
		return (man_er(screen->y, '1', pl, "resoy"));
	while (ln[i] == ' ')
		i++;
	(*scene)->screen = screen;
	return (test_endline(ln, (i += ft_int_len(screen->y)), pl));
}
