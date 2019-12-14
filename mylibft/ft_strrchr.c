/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:53:05 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/10/27 15:21:01 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	search last of occurance of c in s
*/

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	char		*foundptr;

	ptr = s;
	if (c == 0)
	{
		while (*ptr)
			ptr++;
		return ((char *)ptr);
	}
	foundptr = 0;
	while (*ptr)
	{
		if (*ptr == c)
			foundptr = (char *)ptr;
		ptr++;
	}
	return (foundptr);
}
