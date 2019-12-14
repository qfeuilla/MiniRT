/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:52:29 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/10/25 12:34:42 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countchar(int n)
{
	int				count;
	unsigned int	nb;

	count = 1;
	if (n < 0)
	{
		count++;
		nb = (unsigned int)-n;
	}
	else
		nb = (unsigned int)n;
	while (nb / 10 > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	int				i;
	char			*tab;
	unsigned int	nb;

	i = countchar(n);
	if (!(tab = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n < 0)
	{
		nb = (unsigned int)-n;
		tab[0] = '-';
	}
	else
		nb = (unsigned int)n;
	tab[i] = '\0';
	i--;
	while (i >= 0)
	{
		tab[i] = nb % 10 + 48;
		nb = nb / 10;
		if (nb == 0)
			break ;
		i--;
	}
	return (tab);
}
