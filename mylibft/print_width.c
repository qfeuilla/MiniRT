/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:18:58 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:58:50 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_width(t_params *param, int len)
{
	ft_putstr_free(ft_memalloc(len > 0 ? len - 1 : 0, sizeof(char), \
		(ft_c_in_s(param->flag, '0') && param->spec_precision == -1 && \
		!ft_c_in_s(param->flag, '-')) ? '0' : ' '), 1);
}
