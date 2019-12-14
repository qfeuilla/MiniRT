/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:47:16 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/04 14:03:38 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			search_flag(t_params **param, int *start, char *s)
{
	int		i;

	i = 0;
	(*param)->flag = (char *)ft_calloc(5, sizeof(char));
	(*param)->start = (*start)++;
	while (is_flag(s[*start]))
	{
		(*param)->flag[i++] = s[(*start)++];
		if (s[*start] == ' ')
			(*param)->flag[i++] = s[(*start)++];
		while (s[*start] == ' ')
			(*start)++;
	}
}

void			search_width(char *s, int *start, t_params **param)
{
	int			tmp;
	char		*width_precision;

	(*param)->width = 0;
	if (is_width(s[*start]))
	{
		if (s[*start] == '*' && (*start)++)
			(*param)->spec_width = 0;
		else
		{
			(*param)->spec_width = 1;
			tmp = *start;
			while (ft_isdigit(s[tmp]) || s[tmp] == '-')
				tmp++;
			width_precision = (char *)malloc(sizeof(char) * (tmp - *start + 1));
			width_precision[tmp - *start] = '\0';
			tmp = 0;
			while (ft_isdigit(s[*start]) || s[*start] == '-')
				width_precision[tmp++] = s[(*start)++];
			(*param)->width = ft_abs(ft_atoi(width_precision));
			free(width_precision);
		}
	}
	else
		(*param)->spec_width = -1;
}

void			search_precision(char *s, int *start, t_params **param)
{
	int			tmp_pos;
	char		*wp;

	if (s[*start] == '.')
	{
		if (s[++(*start)] == '*' && (*start)++)
			(*param)->spec_precision = 0;
		else if (ft_isdigit(s[*start]) || s[*start] == '-')
		{
			tmp_pos = *start;
			while (ft_isdigit(s[tmp_pos]) || s[tmp_pos] == '-')
				tmp_pos++;
			wp = (char *)malloc(sizeof(char) * (tmp_pos - *start + 1));
			wp[tmp_pos - *start] = '\0';
			tmp_pos = 0;
			while (ft_isdigit(s[*start]) || s[*start] == '-')
				wp[tmp_pos++] = s[(*start)++];
			(*param)->precision = ft_abs(ft_atoi(wp));
			free(wp);
		}
		else
			(*param)->spec_precision = -2;
	}
	else
		(*param)->spec_precision = -1;
}

void			search_length(char *s, int *start, t_params **param)
{
	if (is_length(s[*start]))
	{
		if ((s[*start + 1] == 'h' && s[*start] == 'h') \
			|| (s[*start + 1] == 'l' && s[*start] == 'l'))
		{
			(*param)->double_length = 1;
			(*param)->length = s[*start];
			*start += 2;
		}
		else
		{
			(*param)->double_length = 0;
			(*param)->length = s[*start];
			(*start)++;
		}
	}
}

t_params		*parse_params(char *s, int *start)
{
	t_params	*param;

	param = (t_params *)malloc(sizeof(t_params));
	param->precision = 0;
	param->spec_precision = 1;
	search_flag(&param, start, s);
	search_width(s, start, &param);
	search_precision(s, start, &param);
	search_length(s, start, &param);
	if (is_printf_type(s[*start]))
	{
		param->specifier = s[*start];
		(*start)++;
		param->end = *start;
	}
	else
	{
		param->specifier = 'z';
		param->end = *start;
	}
	return (param);
}
