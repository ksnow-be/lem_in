/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ways3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:09:23 by vferry            #+#    #+#             */
/*   Updated: 2019/04/09 16:00:17 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	for_one1(void)
{
	int		i;
	int		j;

	g_inf.w_ready = malloc(sizeof(t_ways));
	g_inf.w_ready->next = NULL;
	g_inf.w_ready->w = g_inf.w_heap->w;
	i = g_inf.w_ready->w - 1;
	j = 0;
	while (i > 0)
	{
		g_inf.w_ready->way[j] = g_inf.w_heap->way[i];
		i--;
		j++;
	}
	g_inf.sample[0].way = g_inf.w_ready;
	g_inf.sample[0].count = 1;
	g_inf.sam = 0;
}

void	try_to_add(int i, t_ways *buff, int *a, int *t)
{
	int		j;

	j = 0;
	if (diff(&g_inf.sample[i], buff, 0))
	{
		g_inf.sample[g_inf.c_sample].way = malloc(sizeof(t_ways) * 100);
		while (j < g_inf.sample[i].count)
		{
			g_inf.sample[g_inf.c_sample].way[j] = g_inf.sample[i].way[j];
			j++;
		}
		g_inf.sample[g_inf.c_sample].way[j] = *buff;
		g_inf.sample[g_inf.c_sample].count = g_inf.sample[i].count + 1;
		g_inf.sample[g_inf.c_sample].ok = 0;
		g_inf.sample[g_inf.c_sample].w += buff->w;
		ft_memcpy(g_inf.sample[g_inf.c_sample].touch, g_inf.sample[i].touch,
		g_inf.c_room);
		put_way(&g_inf.sample[g_inf.c_sample], buff, 0, 1);
		g_inf.c_sample++;
		*a = 1;
	}
	(*t)++;
}

void	vote_pick(t_sample *p, int *min, int i)
{
	if (p->count)
		p->w = p->w / p->count;
	if (p->count > g_inf.t)
	{
		*min = p->w;
		g_inf.sam = i;
		g_inf.t = p->count;
	}
	else if (p->count == g_inf.t && p->w < *min)
	{
		*min = p->w;
		g_inf.sam = i;
		g_inf.t = p->count;
	}
}

void	add_start(t_sample *p)
{
	int		i;

	i = 0;
	while (i < p->count)
	{
		p->way[i].way[p->way[i].w] = g_inf.r_start;
		p->way[i].w++;
		i++;
	}
}

void	put_count(t_sample *p)
{
	int		i;
	int		j;
	t_ways	*buff;

	i = 0;
	while (i < g_inf.c_ant)
	{
		buff = NULL;
		j = 0;
		while (j < p->count)
		{
			if (!buff || (buff && p->way[j].w + p->way[j].c_ant
			< buff->w + buff->c_ant))
				buff = &p->way[j];
			j++;
		}
		buff->c_ant++;
		i++;
	}
	g_inf.rooms[g_inf.r_start].num_ant = g_inf.num_ants++;
}
