/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:31:57 by vferry            #+#    #+#             */
/*   Updated: 2018/12/03 18:39:50 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenint(int n)
{
	size_t	i;
	int		n1;

	i = 0;
	n1 = n;
	if (n <= 0)
		i = i + 1;
	while (n1 != 0)
	{
		n1 = n1 / 10;
		i++;
	}
	return (i);
}

static	int		ft_razryad(int n)
{
	int i;

	i = 1;
	if (n >= 0)
		while ((n / i) > 9)
			i = i * 10;
	else
		while ((n / i) < -9)
			i = i * 10;
	return (i);
}

static char		*ft_fstr(char *s1, int n, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = ft_razryad(n);
	while (i < len)
	{
		if (n < 0)
		{
			s1[0] = '-';
			i = 1;
			s1[i] = '0' + -(n / j);
			n = -(n % j);
			j = j / 10;
		}
		else
		{
			s1[i] = '0' + (n / j);
			n = n % j;
			j = j / 10;
		}
		i++;
	}
	s1[i] = 0;
	return (s1);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	size_t	i;

	len = ft_lenint(n);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str = ft_fstr(str, n, len);
	return (str);
}
