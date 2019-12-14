/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cy_sp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:47:04 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 15:57:44 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void	free_cys(t_scene **s)
{
	t_cylinder	*cy;
	t_cylinder	*next;

	cy = (*s)->cylinders;
	while (cy)
	{
		next = cy->next;
		free(cy);
		cy = next;
	}
}

void	free_sps(t_scene **s)
{
	t_sphere	*sp;
	t_sphere	*next;

	sp = (*s)->spheres;
	while (sp)
	{
		next = sp->next;
		free(sp);
		sp = next;
	}
}
