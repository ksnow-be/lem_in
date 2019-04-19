/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:17:01 by vferry            #+#    #+#             */
/*   Updated: 2018/12/03 16:53:46 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cont;
	size_t	size;

	size = content_size;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(cont = malloc(content_size)))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		ft_memcpy(cont, content, content_size);
		new->content = cont;
		new->content_size = size;
	}
	new->next = NULL;
	return (new);
}
