/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:41:46 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/02 14:10:50 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copy the src to the destination
*/

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*destptr;
	const char	*srcptr;

	if (src == NULL && dst == NULL)
		return (dst);
	if (dst < src)
	{
		destptr = dst;
		srcptr = src;
		while (n--)
			*destptr++ = *srcptr++;
	}
	else
	{
		destptr = dst + n - 1;
		srcptr = src + n - 1;
		while (n--)
			*destptr-- = *srcptr--;
	}
	return (dst);
}
