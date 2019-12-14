/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:58:00 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:58:07 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_manager(int *bwrote, va_list v1, t_params *param)
{
	if (param->specifier == 'i' || param->specifier == 'd')
		int_manager(v1, bwrote, param);
	else if (param->specifier == '%')
		perc_manager(v1, bwrote, param);
	else if (param->specifier == 'z')
		wrong_manager(v1, bwrote, param);
	else if (param->specifier == 'c')
		char_manager(v1, bwrote, param);
	else if (param->specifier == 's')
		string_manager(v1, bwrote, param);
	else if (param->specifier == 'p')
		ptr_manager(v1, bwrote, param);
	else if (param->specifier == 'u')
		uint_manager(v1, bwrote, param);
	else if (param->specifier == 'x')
		hex_manager(v1, bwrote, param);
	else if (param->specifier == 'X')
		hex_manager(v1, bwrote, param);
	return (param->end);
}

void		printf_loop(t_params **params, int *n, va_list v1, char *s)
{
	int		pos;
	int		act_param;
	int		count;

	count = 0;
	act_param = 0;
	pos = 0;
	params = ft_count_params(&count, (char *)s);
	while (s[pos])
	{
		if (act_param < count && pos == params[act_param]->start)
		{
			pos = ft_manager(n, v1, params[act_param]);
			free(params[act_param]->flag);
			free(params[act_param]);
			act_param++;
		}
		else
		{
			ft_putchar_fd(s[pos++], 1);
			(*n)++;
		}
	}
	free(params);
}

int			ft_printf(const char *s, ...)
{
	t_params	**params;
	int			n;
	va_list		v1;

	params = NULL;
	va_start(v1, s);
	n = 0;
	printf_loop(params, &n, v1, (char *)s);
	va_end(v1);
	return (n);
}
