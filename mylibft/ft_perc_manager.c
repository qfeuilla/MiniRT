/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:41:50 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:58:01 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		printperc_flag(t_params *param, int len)
{
	int		bwrote;

	bwrote = 0;
	bwrote += len > 0 ? len : 0;
	ft_putchar_fd('%', 1);
	print_width(param, len);
	return (bwrote);
}

int		printperc(t_params *param, int len)
{
	int		bwrote;

	bwrote = 0;
	bwrote += len > 0 ? len : 0;
	print_width(param, len);
	ft_putchar_fd('%', 1);
	return (bwrote);
}

void	perc_manager(va_list v1, int *bwrote, t_params *param)
{
	int				width;
	int				len;

	len = 0;
	if (param->spec_width == 0)
		width = va_arg(v1, int);
	else
		width = param->width;
	if (param->spec_precision == 0)
		va_arg(v1, int);
	len = width - len;
	if (param->spec_width < 0)
		(*bwrote)++;
	if (ft_strchr(param->flag, '-'))
		(*bwrote) += printperc_flag(param, len);
	else
		(*bwrote) += printperc(param, len);
}
