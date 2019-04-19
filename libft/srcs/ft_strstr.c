/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:11:08 by vferry            #+#    #+#             */
/*   Updated: 2018/12/01 13:28:54 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (*needle == 0)
		return ((char*)haystack);
	while (haystack[i] != 0)
	{
		j = 0;
		while (needle[j] == haystack[i])
		{
			if (needle[j + 1] == '\0')
				return ((char*)haystack + (i - j));
			j++;
			i++;
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
