/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:02:18 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 18:28:27 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

int			obj_cmp(t_hit obj, t_hit hit)
{
	if (hit.sphere == obj.sphere && hit.sphere != NULL)
		return (1);
	if (hit.cylinder == obj.cylinder && hit.cylinder != NULL)
		return (1);
	if (hit.square == obj.square && hit.square != NULL)
		return (1);
	if (hit.triangle == obj.triangle && hit.triangle != NULL)
		return (1);
	if (hit.plane == obj.plane && hit.plane != NULL)
		return (1);
	return (0);
}
