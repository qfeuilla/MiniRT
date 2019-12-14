/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_each_digi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:21:54 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 15:33:57 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

int				is_digi_type(char c, int good)
{
	if (ft_isdigit(c) || (c == ' ' && good == 0) \
		|| (c == '+' && good == 0) || \
		c == '.' || (c == '-' && good == 0))
		return (1);
	return (0);
}

void			cpy_digi(char *ln, char **digi, int i)
{
	int j;
	int good;

	j = i;
	i = 0;
	good = 0;
	while (is_digi_type(ln[j], good))
	{
		if (ft_isdigit(ln[j]))
			good = 1;
		(*digi)[i++] = ln[j++];
	}
}

int				get_each_digi_i(char *ln, int i, int *error)
{
	int		j;
	char	*digi;
	int		good;
	float	res;

	good = 0;
	j = i;
	while (is_digi_type(ln[j], good))
		if (ft_isdigit(ln[j++]))
			good = 1;
	if (((ln[j] == '+' && good == 1) || \
		(ln[j] == '-' && good == 1)) && ((*error) = 1))
		return (-2);
	if (good == 0 && ((*error) = 1))
		return (-1);
	digi = (char *)malloc(sizeof(char) * (j - i + 1));
	digi[j - i] = '\0';
	cpy_digi(ln, &digi, i);
	res = ft_atof(digi);
	free(digi);
	return ((int)res);
}

float			get_each_digi_f(char *ln, int i, int *error)
{
	int		j;
	char	*digi;
	int		good;
	float	res;

	good = 0;
	j = i;
	while (is_digi_type(ln[j], good))
		if (ft_isdigit(ln[j++]))
			good = 1;
	if (((ln[j] == '+' && good == 1) || \
	(ln[j] == '-' && good == 1)) && ((*error) = 1))
		return (-2);
	if (good == 0 && ((*error) = 1))
		return (-1);
	digi = (char *)malloc(sizeof(char) * (j - i + 1));
	digi[j - i] = '\0';
	cpy_digi(ln, &digi, i);
	if ((!(res = ft_atof(digi)) && ft_int_len(res) > 1) \
			&& ((*error) = 1))
		return (-3);
	free(digi);
	return (res);
}
