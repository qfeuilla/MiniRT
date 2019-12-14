/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:52:58 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:58:41 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		printuint_flag(t_params *param, int p, long to_write, int width)
{
	int		bwrote;
	int		len;

	len = 0;
	bwrote = 0;
	width *= (width < 0) ? -1 : 1;
	if (param->spec_width >= 0)
		len = width - ft_int_len(to_write) + 1 - \
		((param->spec_precision >= 0 && p > ft_int_len(to_write))\
		? p - ft_int_len(to_write) : 0);
	if (param->spec_precision >= 0 && p > ft_int_len(to_write))
	{
		p -= ft_int_len(to_write);
		ft_putstr_free(ft_memalloc(p, sizeof(char), '0'), 1);
		bwrote += p;
	}
	bwrote += ft_int_len(to_write);
	ft_putnbr_fd(to_write, 1);
	ft_putstr_free(ft_memalloc(len > 0 ? len - 1 : 0, sizeof(char), ' '), 1);
	bwrote += len > 0 ? len - 1 : 0;
	return (bwrote);
}

int		printuint(t_params *param, int p, long to_write, int width)
{
	int		bwrote;
	int		len;

	bwrote = 0;
	len = 0;
	width *= (width < 0) ? -1 : 1;
	if (param->spec_width >= 0)
		len = width - ft_int_len(to_write) + 1 - \
		((param->spec_precision >= 0 && p > ft_int_len(to_write))\
		? p - ft_int_len(to_write) : 0);
	ft_putstr_free(ft_memalloc(len > 0 ? len - 1 : 0, sizeof(char), \
	(ft_strchr(param->flag, '0') && param->spec_precision < 0) ? '0' : ' '), 1);
	bwrote += len > 0 ? len - 1 : 0;
	if (param->spec_precision >= 0 && p > ft_int_len(to_write))
	{
		len = p - ft_int_len(to_write);
		ft_putstr_free(ft_memalloc(len, sizeof(char), '0'), 1);
		bwrote += (len > 0 ? len : 0);
	}
	bwrote += ft_int_len(to_write);
	ft_putnbr_fd(to_write, 1);
	return (bwrote);
}

void	uint_manager(va_list v1, int *bwrote, t_params *param)
{
	int		width;
	long	to_write;
	int		p;

	if (param->spec_width == 0)
		width = va_arg(v1, int);
	else
		width = param->width;
	if (param->spec_precision == 0)
		p = va_arg(v1, int);
	else
		p = param->precision;
	to_write = va_arg(v1, unsigned int);
	if ((param->spec_precision == -2 || (p == 0 && param->spec_precision > 0)) \
		&& !to_write && width == 0)
		return ;
	if (width < 0)
		if (!ft_c_in_s(param->flag, '-'))
			param->flag[ft_strlen(param->flag)] = '-';
	if (ft_strchr(param->flag, '-'))
		(*bwrote) += printuint_flag(param, p, to_write, width);
	else
		(*bwrote) += printuint(param, p, to_write, width);
}
