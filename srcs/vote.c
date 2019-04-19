/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vote.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:16:50 by vferry            #+#    #+#             */
/*   Updated: 2019/04/09 16:03:26 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			diff(t_sample *s, t_ways *buff, int i)
{
	while (i < buff->w)
	{
		if (s->touch[buff->way[i]] == 1 && buff->way[i] != g_inf.r_end
		&& buff->way[i] != g_inf.r_start)
			return (0);
		i++;
	}
	return (1);
}

void		put_way(t_sample *s, t_ways *buff, int i, int j)
{
	while (i < buff->w)
	{
		if (j == 1)
			s->touch[buff->way[i]] = 1;
		else if (i != g_inf.r_start)
			s->touch[buff->way[i]] = 0;
		i++;
	}
}

static void	pick3(void)
{
	int		i;
	t_ways	*buff;
	int		min;

	i = 0;
	min = 2147483647;
	while (i < g_inf.c_sample)
	{
		buff = g_inf.w_ready;
		while (buff)
		{
			if (diff(&g_inf.sample[i], buff, 0))
			{
				g_inf.sample[i].way[g_inf.sample[i].count] = *buff;
				g_inf.sample[i].count++;
				put_way(&g_inf.sample[i], buff, 0, 1);
			}
			buff = buff->next;
		}
		vote_pick(&g_inf.sample[i], &min, i);
		i++;
	}
	add_start(&g_inf.sample[g_inf.sam]);
	put_count(&g_inf.sample[g_inf.sam]);
}

static void	pick_2(void)
{
	int		i;
	t_ways	*buff;
	int		t;
	int		a;
	int		j;

	i = 0;
	while (i < g_inf.c_sample)
	{
		buff = g_inf.w_ready;
		a = 0;
		t = 0;
		if (g_inf.sample[i].ok == 0)
			while (buff && t < R && g_inf.sample[i].count < 4)
			{
				try_to_add(i, buff, &a, &t);
				buff = buff->next;
			}
		if (!a && g_inf.sample[i].ok == 0)
			g_inf.sample[i].ok = 1;
		i++;
	}
}

void		pick(void)
{
	int		i;
	int		j;
	t_ways	*buff;

	i = 0;
	buff = g_inf.w_ready;
	while (buff && i < R)
	{
		g_inf.sample[g_inf.c_sample].way = malloc(sizeof(t_ways) * 100);
		g_inf.sample[g_inf.c_sample].way[0] = *buff;
		g_inf.sample[g_inf.c_sample].count = 1;
		g_inf.sample[g_inf.c_sample].ok = 0;
		g_inf.sample[g_inf.c_sample].w = 0;
		g_inf.sample[g_inf.c_sample].w += buff->w;
		ft_bzero(g_inf.sample[g_inf.c_sample].touch, g_inf.c_room);
		j = 0;
		while (j < buff->w)
			g_inf.sample[g_inf.c_sample].touch[buff->way[j++]] = 1;
		g_inf.c_sample++;
		buff = buff->next;
		i++;
	}
	pick_2();
	pick3();
}
