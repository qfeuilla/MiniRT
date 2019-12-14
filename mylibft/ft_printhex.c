/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:54:06 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:58:14 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printhex(long n, int upper)
{
	uintptr_t c;

	if (n >= 16)
		ft_printhex(n / 16, upper);
	if (!upper)
		c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
	else
		c = n % 16 + (n % 16 < 10 ? '0' : 'A' - 10);
	ft_putchar_fd(c, 1);
}
