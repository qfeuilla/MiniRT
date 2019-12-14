/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:07:32 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 18:19:40 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			printstring(t_params *param, char *w, int width, int p)
{
	int		b;
	int		l;

	b = 0;
	l = 0;
	w = (!w) ? ft_strdup("(null)") : w;
	if (param->spec_width >= 0)
		l = width - ((int)ft_strlen(w) > p ? p : (int)ft_strlen(w)) + 1;
	if (ft_strchr(param->flag, '-'))
	{
		b += (l > 0 ? l - 1 : 0) + ((int)ft_strlen(w) >= p ? p : \
									(int)ft_strlen(w));
		while (p-- && *w)
			ft_putchar_fd(*w++, 1);
		print_width(param, l);
	}
	else
	{
		print_width(param, l);
		b += (l > 0 ? l - 1 : 0) + \
		((int)ft_strlen(w) > p ? p : (int)ft_strlen(w));
		while (p-- && *w)
			ft_putchar_fd(*w++, 1);
	}
	return (b);
}

void		string_manager(va_list v1, int *bwrote, t_params *param)
{
	int		width;
	char	*to_write;
	int		prec;

	prec = 10000000;
	if (param->spec_width == 0)
		width = va_arg(v1, int);
	else
		width = param->width;
	if (param->spec_precision == 0)
		prec = va_arg(v1, int);
	else if (param->spec_precision == 1)
		prec = param->precision;
	if (width < 0)
	{
		if (!ft_c_in_s(param->flag, '-'))
			param->flag[ft_strlen(param->flag)] = '-';
		width *= -1;
	}
	to_write = va_arg(v1, char *);
	if (param->spec_precision == -2)
		return ;
	(*bwrote) += printstring(param, to_write, width, prec);
}
