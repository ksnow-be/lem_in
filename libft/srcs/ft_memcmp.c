/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:22:47 by vferry            #+#    #+#             */
/*   Updated: 2018/11/30 12:20:41 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*ss;

	s = (unsigned char*)s1;
	ss = (unsigned char*)s2;
	i = 0;
	while ((i < n) && s[i] == ss[i])
		i++;
	if (i != n)
		return (s[i] - ss[i]);
	return (0);
}
