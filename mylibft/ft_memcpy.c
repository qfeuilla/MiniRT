/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:55:31 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/02 14:10:38 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destptr;
	const char	*srcptr;

	if (src == NULL && dst == NULL)
		return (dst);
	destptr = dst;
	srcptr = src;
	while (n--)
		*destptr++ = *srcptr++;
	return (dst);
}
