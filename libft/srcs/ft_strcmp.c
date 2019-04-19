/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:50:02 by vferry            #+#    #+#             */
/*   Updated: 2018/11/29 20:44:30 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int dif;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	dif = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (dif);
}
