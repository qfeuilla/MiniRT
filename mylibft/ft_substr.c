/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:31:21 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/10/25 12:55:34 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*rstr;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i <= start)
		return (ft_strdup(""));
	i = 0;
	while (i < len && s[start + i])
		i++;
	if (!(rstr = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[start])
		rstr[i++] = s[start++];
	rstr[i] = '\0';
	return (rstr);
}
