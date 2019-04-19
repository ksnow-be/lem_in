/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:01:30 by vferry            #+#    #+#             */
/*   Updated: 2018/12/04 19:45:14 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buff;

	if (alst && del)
		while (*alst)
		{
			buff = (**alst).next;
			del((**alst).content, (**alst).content_size);
			free(*alst);
			*alst = buff;
		}
}
