/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:35:01 by vferry            #+#    #+#             */
/*   Updated: 2018/12/03 13:56:12 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_strstart(char const *s)
{
	size_t	start;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
	{
		if (s[start] == '\0')
			return (0);
		start++;
	}
	return (start);
}

static size_t	ft_strend(char const *s)
{
	size_t	end;

	end = ft_strlen(s) - 1;
	if (end > 0)
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		{
			if (end == 0)
				return (0);
			end--;
		}
	return (end + 1);
}

static char		*ft_strcp(char const *s)
{
	size_t	start;
	size_t	end;
	int		i;
	char	*trim2;

	i = 0;
	start = ft_strstart(s);
	end = ft_strend(s);
	trim2 = NULL;
	if (end == 0)
		start = 0;
	if (!(trim2 = (char*)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	trim2 = ft_strsub(s, (unsigned int)start, (end - start));
	return (trim2);
}

char			*ft_strtrim(char const *s)
{
	char	*trim;

	trim = NULL;
	if (s != NULL)
		trim = ft_strcp(s);
	return (trim);
}
