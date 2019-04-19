/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ways2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:07:22 by vferry            #+#    #+#             */
/*   Updated: 2019/04/09 15:59:28 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	up_tail(t_ways **head, t_ways *cur)
{
	t_ways	*buff;

	buff = *head;
	if (!cur)
		return ;
	while (buff && buff->next)
		buff = buff->next;
	if (!buff)
		*head = cur;
	else
		buff->next = cur;
}

t_ways	*new_way(int from, int weight)
{
	t_ways	*new;

	new = malloc(sizeof(t_ways));
	new->w = weight;
	new->way[0] = from;
	new->way[1] = -1;
	new->c_ant = 0;
	new->next = NULL;
	return (new);
}

t_ways	*take_tail(t_ways **head)
{
	t_ways	*buff;

	if (!*head)
		return (NULL);
	buff = *head;
	*head = (*head)->next;
	return (buff);
}

t_ways	*copy_way(t_ways *buff, int room)
{
	t_ways	*new;
	int		i;
	int		j;

	new = malloc(sizeof(t_ways));
	new->w = buff->w + 1;
	new->way[0] = room;
	i = 0;
	j = 1;
	while (j < ROOM && i < ROOM && buff->way[i] != -1)
	{
		new->way[j] = buff->way[i];
		i++;
		j++;
	}
	new->way[j] = -1;
	new->c_ant = 0;
	new->next = NULL;
	return (new);
}

void	way_built(t_ways *buff)
{
	int		i;

	i = 0;
	while (i < g_inf.c_room)
	{
		if (g_inf.connect[buff->way[0]][i] > 0 && i != buff->way[0]
		&& repeat(buff->way, i, buff->w + 1) == 1
		&& (((g_inf.rooms[buff->way[0]].weight[0] > g_inf.rooms[i].weight[0])
		|| g_inf.rooms[i].weight[1] < W2) || buff->way[0] == g_inf.r_start))
		{
			g_inf.rooms[i].weight[1]++;
			if (i == g_inf.r_end)
			{
				up_tail(&g_inf.w_ready, copy_way(buff, i));
				g_inf.c_ways++;
			}
			else
				up_tail(&g_inf.w_heap, copy_way(buff, i));
		}
		i++;
	}
}
