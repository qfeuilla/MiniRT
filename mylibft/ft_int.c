/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:01:39 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:57:42 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		printint_flag(t_params *param, int precision, long to_write, int len)
{
	int		bwrote;

	bwrote = 0;
	bwrote += len > 0 ? len - 1 : 0;
	if (ft_c_in_s(param->flag, ' ') && to_write >= 0 && \
		!ft_c_in_s(param->flag, '+') && ++bwrote)
	{
		ft_putchar_fd(' ', 1);
		if (param->spec_width >= 0 && --bwrote > -10)
			len--;
	}
	if (to_write < 0 && param->spec_precision != -1)
		len--;
	bwrote += intutils(param, &to_write, len, precision);
	bwrote += ft_int_len(to_write);
	if (!(precision == 0 && param->spec_precision >= 0 && to_write == 0))
		ft_putnbr_fd(to_write, 1);
	else
		bwrote--;
	ft_putstr_free(ft_memalloc(len > 0 ? len - 1 : 0, sizeof(char), \
		(ft_c_in_s(param->flag, '0') && param->spec_precision < 0 && \
		!(ft_c_in_s(param->flag, '-'))) ? '0' : ' '), 1);
	return (bwrote);
}

int		intutils(t_params *param, long *w, int len, int precision)
{
	int		bwrote;

	bwrote = 0;
	if (param->spec_precision != -1)
	{
		if ((*w) < 0 && ++bwrote && ((*w) *= -1) && len-- > -10000)
			ft_putchar_fd('-', 1);
		else if ((*w) >= 0 && ft_c_in_s(param->flag, '+') && ++bwrote)
			ft_putchar_fd('+', 1);
		if (precision > ft_int_len(*w))
		{
			len = precision - ft_int_len((*w));
			ft_putstr_free(ft_memalloc(len, sizeof(char), '0'), 1);
			bwrote += (len > 0 ? len : 0);
		}
	}
	else if (!(ft_c_in_s(param->flag, '0') && param->spec_precision < 0 && \
	!ft_c_in_s(param->flag, '-')))
	{
		if ((*w) < 0 && ++bwrote && --len && ((*w) *= -1))
			ft_putchar_fd('-', 1);
		else if ((*w) >= 0 && ft_c_in_s(param->flag, '+') && ++bwrote)
			ft_putchar_fd('+', 1);
	}
	return (bwrote);
}

int		printint(t_params *param, int p, long w, int len)
{
	int		bwrote;
	int		neg;

	neg = (w > 0) ? 0 : 1;
	bwrote = 0;
	if (ft_c_in_s(param->flag, '0') && param->spec_precision == -1)
		if (w < 0 && ++bwrote && (w *= -1))
			ft_putchar_fd('-', 1);
	if (ft_c_in_s(param->flag, ' ') && neg == 0 && \
		!ft_c_in_s(param->flag, '+') && ++bwrote && \
		(len -= (param->spec_width >= 0) ? 1 : 0) > -10)
		ft_putchar_fd(' ', 1);
	if (w < 0 && ft_c_in_s(param->flag, '0') && p - ft_int_len(w) > 0)
		len--;
	print_width(param, len);
	bwrote += intutils(param, &w, len, p) + ((len > 0) ? len - 1 : 0);
	if (w < 0)
		bwrote--;
	bwrote += ft_int_len(w);
	if (!(p == 0 && param->spec_precision >= 0 && w == 0))
		ft_putnbr_fd(w, 1);
	else
		bwrote--;
	return (bwrote);
}

int		manage_i(t_params *param, int p, long to_write, int len)
{
	int		bwrote;

	bwrote = 0;
	if (ft_c_in_s(param->flag, '-'))
		bwrote += printint_flag(param, p, to_write, len);
	else
		bwrote += printint(param, p, to_write, len);
	return (bwrote);
}

void	int_manager(va_list v1, int *bwrote, t_params *param)
{
	int		w;
	long	to_write;
	int		p;
	int		len;

	len = 0;
	if (param->spec_width == 0)
		w = va_arg(v1, int);
	else
		w = param->width;
	if (param->spec_precision == 0)
		p = va_arg(v1, int);
	else
		p = param->precision;
	if (!ft_c_in_s(param->flag, '-') && w < 0)
		param->flag[ft_strlen(param->flag)] = '-';
	w *= (w < 0) ? -1 : 1;
	to_write = va_arg(v1, int);
	if (param->spec_precision == -2 && !to_write)
		return ;
	if (param->spec_width >= 0)
		len = w - ft_int_len(to_write) + 1 - ((param->spec_precision >= 0 && \
		p > ft_int_len(to_write)) ? p - ft_int_len(to_write) : 0);
	(*bwrote) += manage_i(param, p, to_write, len);
}
