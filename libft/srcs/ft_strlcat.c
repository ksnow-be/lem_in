/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:25:05 by vferry            #+#    #+#             */
/*   Updated: 2018/12/03 19:24:46 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	srav(size_t l1, size_t l2)
{
	if (l1 <= l2)
		return (l1);
	return (l2);
}

size_t			ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	while ((i + len_dst + 1) < len && src[i])
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	len_src += srav(len, len_dst);
	return (len_src);
}
