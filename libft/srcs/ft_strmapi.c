/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:34:12 by vferry            #+#    #+#             */
/*   Updated: 2018/12/03 13:54:24 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*str;

	i = 0;
	str = NULL;
	if ((s != NULL) && (f != NULL))
	{
		len = ft_strlen(s);
		if (!(str = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		if ((s != NULL) && (f != NULL) && (str != NULL))
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
		str[i] = 0;
	}
	return (str);
}
