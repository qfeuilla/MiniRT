/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:51:13 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 13:57:32 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_params		**ft_count_params(int *n, char *s)
{
	int			i;
	int			act_param;
	t_params	**params;

	act_param = 0;
	i = 0;
	while (s[i])
		if (s[i++] == '%' && (*n += 1))
			if (s[i] == '%')
				i++;
	params = (t_params **)malloc(*n * sizeof(t_params *));
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			params[act_param++] = parse_params(s, &i);
		else
			i++;
	}
	return (params);
}
