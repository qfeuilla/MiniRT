/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:08:01 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/02 13:36:49 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memalloc(size_t nmemb, size_t size, int c)
{
	char	*ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (!(ptr = malloc((nmemb + 1) * size)))
		return (NULL);
	ft_memset(ptr, c, nmemb * size);
	ptr[nmemb * size] = '\0';
	return (ptr);
}
