/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:31:50 by vferry            #+#    #+#             */
/*   Updated: 2018/12/03 18:41:35 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_izm(unsigned char *dst, unsigned char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

static void	ft_izn(unsigned char *dst, unsigned char *src, size_t len)
{
	size_t	i;

	i = len;
	while (i--)
		dst[i] = src[i];
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	if (src1 > dst1)
		ft_izm(dst1, src1, len);
	else if (src1 == dst1)
		return (dst);
	else
		ft_izn(dst1, src1, len);
	return (dst);
}
