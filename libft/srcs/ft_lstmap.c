/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:39:15 by vferry            #+#    #+#             */
/*   Updated: 2018/12/04 19:43:33 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstdelmap(t_list *lst)
{
	t_list	*buf;

	while (lst)
	{
		buf = lst->next;
		free(lst);
		lst = buf;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*prev;

	start = NULL;
	if (lst && f)
	{
		start = f(lst);
		prev = start;
		lst = lst->next;
		while (lst)
		{
			if (!(prev->next = f(lst)))
			{
				ft_lstdelmap(start);
				return (NULL);
			}
			prev = prev->next;
			lst = lst->next;
		}
	}
	return (start);
}
