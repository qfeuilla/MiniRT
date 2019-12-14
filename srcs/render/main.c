/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:24:50 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 17:02:25 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

int		main(int ac, char **av)
{
	int			fd;
	t_scene		*scene;

	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!(scene = parser(fd)))
			return (0);
		if (!manage_window(scene))
			ft_printf("Error\nwhen close window");
	}
	else if (ac == 1)
		ft_printf("Error\ntoo few arguments");
	else
		ft_printf("Error\ntoo much arguments");
	return (0);
}
