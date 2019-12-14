/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:57:43 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/02 13:38:00 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	allocate space and fill with 0
*/

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	int				stop;

	stop = size * count;
	if (stop <= 0)
		return (ft_strdup(""));
	if (!(ptr = malloc(stop)))
		return (NULL);
	while (stop > 0)
		ptr[--stop] = 0;
	return (ptr);
}
