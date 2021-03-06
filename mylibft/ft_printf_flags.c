/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:57:23 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:58:04 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_printf_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || \
		c == 'X' || c == 'f' || c == 'F' || c == 'e' || c == 'E' || \
		c == 'g' || c == 'G' || c == 'a' || c == 'A' || c == 'c' || \
		c == 's' || c == 'p' || c == 'n' || c == '%')
		return (1);
	return (0);
}

int			is_flag(char c)
{
	return ((c == '-' || c == ' ' || c == '+' ||\
				c == '#' || c == '0') ? 1 : 0);
}

int			is_width(char c)
{
	return ((c == '*' || (c >= '0' && c <= '9') || c == '-') ? 1 : 0);
}

int			is_length(char c)
{
	return ((c == 'h' || c == 'l') ? 1 : 0);
}
