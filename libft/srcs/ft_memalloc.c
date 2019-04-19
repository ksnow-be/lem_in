/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:34:11 by vferry            #+#    #+#             */
/*   Updated: 2018/12/03 13:51:30 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*area;
	size_t			i;

	i = 0;
	if (!(area = malloc(size)))
		return (NULL);
	while (i < size)
	{
		area[i] = 0;
		i++;
	}
	return ((void*)area);
}
