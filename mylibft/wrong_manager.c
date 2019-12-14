/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:27:43 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:59:05 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	wrong_manager(va_list v1, int *bwrote, t_params *param)
{
	int		width;
	int		len;

	len = 0;
	if (param->spec_width == 0)
		width = ft_abs(va_arg(v1, int));
	else
		width = param->width;
	if (param->spec_precision == 0)
		va_arg(v1, int);
	len = width;
	print_width(param, len);
	(*bwrote) += (len > 0) ? len - 1 : 0;
}
