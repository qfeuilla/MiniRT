/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:05:05 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:57:29 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			printchar(t_params *param, char to_write, int len)
{
	int		bwrote;

	bwrote = 0;
	if (ft_strchr(param->flag, '-'))
	{
		bwrote++;
		ft_putchar_fd(to_write, 1);
		print_width(param, len);
		bwrote += len > 0 ? len - 1 : 0;
	}
	else
	{
		print_width(param, len);
		bwrote += len > 0 ? len - 1 : 0;
		bwrote++;
		ft_putchar_fd(to_write, 1);
	}
	return (bwrote);
}

void		char_manager(va_list v1, int *bwrote, t_params *param)
{
	int		width;
	char	to_write;
	int		len;

	len = 0;
	if (param->spec_width == 0)
		width = va_arg(v1, int);
	else if (param->spec_width == 1)
		width = param->width;
	if (param->spec_precision == 0)
		va_arg(v1, int);
	to_write = va_arg(v1, int);
	if (param->spec_width >= 0)
		len = width;
	(*bwrote) += printchar(param, to_write, len);
}
