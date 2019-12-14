/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:15:57 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 16:53:00 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

char			*atof_util(char **num, int *i)
{
	char	*ptr;

	*num = &(*num)[(*i)];
	(*i) = 0;
	while (ft_isdigit((*num)[(*i)]))
		(*i)++;
	ptr = (char *)malloc(sizeof(char) * ((*i) + 1));
	ptr[(*i)] = '\0';
	(*i) = -1;
	while (ft_isdigit((*num)[++(*i)]))
		ptr[(*i)] = (*num)[(*i)];
	return (ptr);
}

float			ret_atof(char **ptr, float sign)
{
	float res;

	res = ft_atoi(*ptr);
	free(*ptr);
	return (res * sign);
}

float			ft_atof(char *num)
{
	int		i;
	char	*ptr;
	char	*p2;
	float	res;
	float	sign;

	i = 0;
	sign = 1;
	while (num[i] == ' ' || num[i] == '+')
		i++;
	if (num[i] == '-' && (sign = -1) == -1)
		i++;
	ptr = atof_util(&num, &i);
	if (!(num[i] == '.' || !num[i]))
	{
		free(ptr);
		return (0);
	}
	if (num[i++] == '\0')
		return (ret_atof(&ptr, sign));
	p2 = atof_util(&num, &i);
	res = ft_atoi(ptr) + (ft_atoi(p2) * pow(10, -(ft_int_len(ft_atoi(p2)))));
	free(ptr);
	free(p2);
	return (res * sign);
}
