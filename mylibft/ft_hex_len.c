/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:54:51 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/10/27 15:18:49 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hex_len(uintptr_t n, uintptr_t num)
{
	num++;
	if (n >= 16)
		return (ft_hex_len(n / 16, num));
	else
		return (num);
}
