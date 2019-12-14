/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:30:46 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/10/21 14:18:53 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*list;
	t_list		*temp;

	if (!del || !lst)
		return ;
	temp = *lst;
	while (temp)
	{
		list = temp->next;
		ft_lstdelone(temp, del);
		temp = list;
	}
}
