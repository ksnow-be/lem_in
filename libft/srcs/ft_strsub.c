/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:32:39 by vferry            #+#    #+#             */
/*   Updated: 2018/12/03 13:55:08 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy(char const *s, size_t n)
{
	size_t	i;
	char	*subs;

	i = 0;
	subs = NULL;
	if ((subs = (char*)malloc(sizeof(char) * n + 1)))
	{
		while (i < n)
		{
			subs[i] = s[i];
			i++;
		}
		subs[i] = '\0';
	}
	return (subs);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	l;
	char	*subs;
	size_t	lens;

	subs = NULL;
	lens = start + len;
	l = 0;
	if (s != NULL)
	{
		l = ft_strlen(s);
		if (start <= l && l >= lens)
			subs = ft_copy(&s[start], len);
	}
	return (subs);
}
