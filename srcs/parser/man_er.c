/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_er.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:13:46 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 14:04:55 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

void		man_er_util_1(int ret, char axe, int pl, char *type)
{
	if (ret == -1)
	{
		ft_printf("ln %d: ", pl);
		ft_printf("No digit in the %c axis %s", axe, type);
	}
	if (ret == -2)
	{
		ft_printf("ln %d: ", pl);
		ft_printf("Invalid operand or no value in the %c axis %s", axe, type);
	}
	if (ret == -3)
	{
		ft_printf("ln %d: ", pl);
		ft_printf("error in orientation\n");
		ft_printf(" '-> maybe orientation muste be normalized (-1 to 1)\n");
		ft_printf(" '-> maybe orientation is non precised (0, 0, 0)");
	}
	if (ret == -4)
	{
		ft_printf("ln %d: ", pl);
		ft_printf("Error after %c axis %s\n", axe, type);
		ft_printf("  '->  Maybe it's needed more values\n");
		ft_printf("  '->  Maybe value is bad type");
	}
}

void		man_er_util_2(int ret, char axe, int pl, char *type)
{
	if (ret == -5)
	{
		ft_printf("ln %d: Bad number in the %c axis %s\n", pl, axe, type);
		ft_printf("  '->  Bad value for color");
	}
	if (ret == -6)
	{
		ft_printf("ln %d: ", pl);
		ft_printf("Already defined");
	}
	if (ret == -7)
	{
		ft_printf("ln %d: ", pl);
		ft_printf("Number %s is too hight", type);
	}
	if (ret == -8)
	{
		ft_printf("ln %d: ", pl);
		ft_printf("Bad character at end of line");
	}
	if (ret == -9)
	{
		ft_printf("ln %d: ", pl);
		ft_printf("No identifier at the start of the line");
	}
}

t_vec3		man_er(int ret, char axe, int pl, char *type)
{
	ft_printf("Error\n");
	man_er_util_1(ret, axe, pl, type);
	man_er_util_2(ret, axe, pl, type);
	ft_printf("\n");
	return (V_FALSE);
}
