/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:33:11 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/10/27 15:21:21 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	search c in s
*/

char	*ft_strchr(const char *s, int c)
{
	const char *ptr;

	ptr = s;
	while (*ptr && *ptr != c)
		ptr++;
	return ((*ptr == c) ? (char *)ptr : 0);
}
