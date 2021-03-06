/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_in_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:53:02 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/01 21:20:32 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_c_in_s(char *s, char c)
{
	char *ptr;

	ptr = s;
	while (*ptr && *ptr != c)
		ptr++;
	return ((*ptr == c) ? 1 : 0);
}
