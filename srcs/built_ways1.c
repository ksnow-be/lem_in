/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ways1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:50:15 by vferry            #+#    #+#             */
/*   Updated: 2019/04/17 15:33:14 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_ways(void)
{
	if (g_inf.connect[g_inf.r_start][g_inf.r_end] == 1 ||
			g_inf.connect[g_inf.r_end][g_inf.r_start] == 1)
	{
		g_inf.flag = 1;
		print();
	}
	else if (g_inf.c_ant < 2)
		for_one();
	else
		for_crowd();
}

void	look_way(void)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	g_inf.tail[0] = g_inf.r_end;
	k = 1;
	g_inf.rooms[g_inf.tail[0]].weight[0] = 0;
	while (i < k)
	{
		j = 0;
		while (j < g_inf.c_room)
		{
			if (g_inf.connect[g_inf.tail[i]][j] == 1
			&& g_inf.rooms[j].weight[0] == -1)
			{
				g_inf.rooms[j].weight[0] =
				g_inf.rooms[g_inf.tail[i]].weight[0] + 1;
				g_inf.tail[k] = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	for_crowd(void)
{
	t_ways	*buff;

	up_tail(&g_inf.w_heap, new_way(g_inf.r_start, 0));
	while (g_inf.w_heap)
	{
		buff = take_tail(&g_inf.w_heap);
		if (buff == NULL)
			ft_clean("No way to end!", 1);
		way_built(buff);
		way_destroy(buff);
	}
	if (g_inf.c_ways == 0)
		ft_clean("No way to end!", 1);
}

void	for_one(void)
{
	int		dst;

	g_inf.w_heap = malloc(sizeof(t_ways));
	g_inf.w_heap->way[0] = g_inf.r_start;
	g_inf.rooms[g_inf.r_start].weight[0] = ROOM * 2;
	g_inf.w_heap->w = 1;
	while ((dst = less_weight(g_inf.w_heap->way[g_inf.w_heap->w - 1])) >= 0)
	{
		g_inf.w_heap->way[g_inf.w_heap->w] = dst;
		g_inf.w_heap->w++;
	}
	g_inf.w_heap->way[g_inf.w_heap->w] = -1;
	for_one1();
}
