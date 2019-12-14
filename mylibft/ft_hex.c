/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:12:09 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:57:37 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		printhex_flag(t_params *param, long to_write, int len, int precision)
{
	int		bwrote;

	bwrote = 0;
	to_write *= (to_write < 0) ? -1 : 1;
	if (param->spec_precision >= 0 && precision > ft_hex_len(to_write, 0))
	{
		precision -= ft_hex_len(to_write, 0);
		ft_putstr_free(ft_memalloc(precision, sizeof(char), '0'), 1);
		bwrote += precision;
	}
	bwrote += (len > 0 ? len - 1 : 0) + ft_hex_len(to_write, 0);
	if (!(param->spec_precision == -2 && !to_write))
		ft_printhex(to_write, param->specifier == 'X');
	else
		ft_putchar_fd(' ', 1);
	ft_putstr_free(ft_memalloc(len > 0 ? len - 1 : 0, sizeof(char), ' '), 1);
	return (bwrote);
}

int		printhex(t_params *param, long to_write, int len, int precision)
{
	int		bwrote;

	bwrote = 0;
	to_write *= (to_write < 0) ? -1 : 1;
	bwrote += (len > 0 ? len - 1 : 0) + ft_hex_len(to_write, 0);
	ft_putstr_free(ft_memalloc(len > 0 ? len - 1 : 0, sizeof(char), \
	(ft_strchr(param->flag, '0') && param->spec_precision < 0) ? '0' : ' '), 1);
	if (param->spec_precision >= 0 && precision > ft_hex_len(to_write, 0))
	{
		len = precision - ft_hex_len(to_write, 0);
		ft_putstr_free(ft_memalloc(len, sizeof(char), '0'), 1);
		bwrote += len;
	}
	if (!(param->spec_precision == -2 && !to_write))
		ft_printhex(to_write, param->specifier == 'X');
	else
		ft_putchar_fd(' ', 1);
	return (bwrote);
}

void	hex_manager(va_list v1, int *bwrote, t_params *param)
{
	int				width;
	long			to_write;
	int				len;
	int				precision;

	len = 0;
	if (param->spec_width == 0)
		width = va_arg(v1, int);
	else
		width = param->width;
	if (param->spec_precision == 0)
		precision = va_arg(v1, int);
	else
		precision = param->precision;
	to_write = va_arg(v1, unsigned int);
	if ((param->spec_precision == -2 || (precision == 0 && \
		param->spec_precision > 0)) && !to_write && width == 0)
		return ;
	len = width - ft_hex_len(to_write, 0) + 1 - \
	((param->spec_precision >= 0 && precision > ft_hex_len(to_write, 0)) \
	? precision - ft_hex_len(to_write, 0) : 0);
	if (ft_strchr(param->flag, '-'))
		(*bwrote) += printhex_flag(param, to_write, len, precision);
	else
		(*bwrote) += printhex(param, to_write, len, precision);
}
