/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:10:02 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:58:18 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			printptr_f(t_params *param, uintptr_t to_write, int len, int prec)
{
	int		bwrote;

	bwrote = 0;
	if (ft_strchr(param->flag, '-'))
	{
		ft_putstr_free("0x", 0);
		if (param->spec_precision >= 0 && prec > ft_hex_len(to_write, 0))
		{
			prec = prec - ft_hex_len(to_write, 0);
			ft_putstr_free(ft_memalloc(prec, sizeof(char), '0'), 1);
			bwrote += (prec > 0 ? prec : 0);
		}
		ft_printhex(to_write, 0);
		ft_putstr_free(ft_memalloc(len > 0 ? len - 1 : 0, \
						sizeof(char), ' '), 1);
		bwrote += (len > 0 ? len - 1 : 0) + ft_hex_len(to_write, 0) + 2;
	}
	return (bwrote);
}

int			ptr_util(t_params *param, uintptr_t to_write, int len, int prec)
{
	int		bwrote;

	bwrote = 0;
	if (!ft_strchr(param->flag, '0'))
		ft_putstr_free(ft_memalloc(len > 0 ? len - 1 : 0, \
				sizeof(char), ' '), 1);
	ft_putstr_free("0x", 0);
	if (ft_strchr(param->flag, '0'))
		print_width(param, len);
	if (param->spec_precision >= 0 && prec > ft_hex_len(to_write, 0))
	{
		prec = prec - ft_hex_len(to_write, 0);
		ft_putstr_free(ft_memalloc(prec, sizeof(char), '0'), 1);
		bwrote += (prec > 0 ? prec : 0);
	}
	ft_printhex(to_write, 0);
	bwrote += (len > 0 ? len - 1 : 0) + ft_hex_len(to_write, 0) + 2;
	return (bwrote);
}

int			printptr(t_params *param, uintptr_t to_write, int width, int prec)
{
	int		bwrote;
	int		len;

	len = 0;
	bwrote = 0;
	if (param->spec_width >= 0)
		len = width - (ft_hex_len(to_write, 0) + 2) + 1 - \
		((param->spec_precision >= 0 && prec > ft_hex_len(to_write, 0)) \
		? prec - ft_hex_len(to_write, 0) : 0);
	if (ft_strchr(param->flag, '-'))
		bwrote += printptr_f(param, to_write, len, prec);
	else
		bwrote += ptr_util(param, to_write, len, prec);
	return (bwrote);
}

void		ptr_manager(va_list v1, int *bwrote, t_params *param)
{
	int				width;
	uintptr_t		to_write;
	int				precision;

	if (param->spec_width == 0)
		width = va_arg(v1, int);
	else if (param->spec_width == 1)
		width = param->width;
	if (param->spec_precision == 0)
		precision = va_arg(v1, int);
	else
		precision = param->precision;
	to_write = (uintptr_t)va_arg(v1, void *);
	if ((param->spec_precision == -2 || (precision == 0 && \
	param->spec_precision > 0)) && !to_write)
	{
		ft_putstr_free("0x", 0);
		(*bwrote) += 2;
		return ;
	}
	(*bwrote) += printptr(param, to_write, width, precision);
}
