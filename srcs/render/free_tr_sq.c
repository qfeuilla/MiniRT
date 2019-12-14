/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tr_sq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:45:17 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 15:57:41 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void	free_trs(t_scene **s)
{
	t_triangle	*tr;
	t_triangle	*next;

	tr = (*s)->triangles;
	while (tr)
	{
		next = tr->next;
		free(tr);
		tr = next;
	}
}

void	free_sqs(t_scene **s)
{
	t_square	*sq;
	t_square	*next;

	sq = (*s)->squares;
	while (sq)
	{
		next = sq->next;
		free(sq);
		sq = next;
	}
}
