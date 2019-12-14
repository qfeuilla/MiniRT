/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:33:22 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/10/23 14:31:10 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** concat the strings in the first and return len of dest plus len of src
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		sze;
	size_t		dlen;

	sze = size;
	d = dst;
	s = src;
	while (sze-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	sze = size - dlen;
	if (size == dlen)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (sze != 1)
		{
			*d++ = *s;
			sze--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
