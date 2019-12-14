/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:18:59 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/10/21 14:23:24 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*list;
	t_list		*temp;

	list = NULL;
	if (lst && f)
	{
		if (!(list = ft_lstnew(f(lst->content))))
			return (NULL);
		temp = list;
		while (lst->next)
		{
			lst = lst->next;
			if (!(temp->next = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&list, del);
				return (NULL);
			}
			temp = temp->next;
		}
	}
	return (list);
}
