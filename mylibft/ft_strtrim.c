/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:55:16 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/10/25 12:58:14 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	int		len;
	char	*str;
	char	*str2;

	str2 = (char *)s;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(str2);
	while (ft_strchr((char *)set, str2[len - 1]) != 0)
		len--;
	i = -1;
	while (ft_strchr((char *)set, str2[++i]) != 0)
		len--;
	if (len <= 0)
		len = 0;
	if (!(str = ((char*)malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	str2 = str2 + i;
	i = -1;
	while (++i < len)
		str[i] = *str2++;
	str[i] = '\0';
	return (str);
}
