/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:22:36 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 17:22:35 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

int		vector_cmp(t_vec3 v1, t_vec3 v2)
{
	int	i;

	i = 0;
	if (!(v1.x == v2.x))
		return (0);
	if (!(v1.y == v2.y))
		return (0);
	if (!(v1.z == v2.z))
		return (0);
	return (1);
}
