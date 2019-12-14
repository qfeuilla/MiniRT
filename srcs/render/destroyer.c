/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:20:39 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 17:16:44 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void	free_pls(t_scene **s)
{
	t_plane	*pl;
	t_plane	*next;

	pl = (*s)->planes;
	while (pl)
	{
		next = pl->next;
		free(pl);
		pl = next;
	}
}

int		destroy_n_exit(void *mlx, void *g_win, t_scene **scene)
{
	free((*scene)->al);
	free((*scene)->screen);
	free_cams(scene);
	free_trs(scene);
	free_sqs(scene);
	free_cys(scene);
	free_sps(scene);
	free_pls(scene);
	free_lis(scene);
	mlx_destroy_window(mlx, g_win);
	free(mlx);
	exit(0);
}
