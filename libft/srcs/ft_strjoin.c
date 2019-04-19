/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:15:02 by vferry            #+#    #+#             */
/*   Updated: 2018/12/03 18:50:25 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strconc(const char *s1, const char *s2, size_t le1, size_t le2)
{
	size_t	i;
	size_t	j;
	char	*conc;

	i = 0;
	j = 0;
	conc = NULL;
	if ((conc = (char*)malloc(sizeof(char) * le1 + le2 + 1)))
	{
		while (i < le1)
		{
			conc[i] = s1[i];
			i++;
		}
		while (j < le2)
		{
			conc[i + j] = s2[j];
			j++;
		}
		conc[i + j] = '\0';
	}
	return (conc);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*conc;

	l1 = 0;
	l2 = 0;
	conc = NULL;
	if (s1 && s2)
	{
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		conc = ft_strconc(s1, s2, l1, l2);
	}
	return (conc);
}
