/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:02:04 by vferry            #+#    #+#             */
/*   Updated: 2018/11/28 19:10:31 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (s[i] == c)
		return ((char*)s + i);
	if (s[j] == c)
		return ((char*)s + j);
	else
		return (NULL);
}
