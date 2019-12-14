/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:32:06 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/10/23 14:17:04 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies no more than n bytes, while c is not found
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*destptr;
	const char	*srcptr;

	destptr = dst;
	srcptr = src;
	while (n--)
	{
		*destptr = *srcptr;
		if (*srcptr == (char)c)
			return (++destptr);
		destptr++;
		srcptr++;
	}
	return (NULL);
}
