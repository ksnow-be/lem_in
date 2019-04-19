/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_helper2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:15:08 by vferry            #+#    #+#             */
/*   Updated: 2019/04/03 17:01:11 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		less_weight(int src)
{
	int	dst;
	int	i;

	i = 0;
	dst = src;
	if (src == g_inf.r_end)
		return (-1);
	while (i < g_inf.c_room)
	{
		if (g_inf.connect[src][i] != 0 && i != g_inf.r_start)
			if (g_inf.rooms[i].weight[0] < g_inf.rooms[dst].weight[0])
				dst = i;
		i++;
	}
	return (dst);
}

int		repeat(int *way, int room, int size)
{
	int	i;

	i = 0;
	while (i < size)
		if (way[i] == room)
			return (0);
		else
			i++;
	return (1);
}
