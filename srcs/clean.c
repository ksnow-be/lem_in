/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:46:58 by vferry            #+#    #+#             */
/*   Updated: 2019/04/16 09:57:00 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	clean_heap(t_ways *del)
{
	t_ways *buff;

	while (del)
	{
		buff = del;
		del = del->next;
		free(buff);
	}
}

static void	clean_connect(char **del, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(del[i]);
		i++;
	}
	free(del);
}

static void	clean_room(void)
{
	int i;

	i = 0;
	while (i < g_inf.c_room)
	{
		free(g_inf.rooms[i].name);
		i++;
	}
}

static void	clean_sample(void)
{
	int		i;

	i = 0;
	while (i < g_inf.c_sample)
	{
		free(g_inf.sample[i].way);
		i++;
	}
}

void		ft_clean(char *str, int i)
{
	if (g_inf.c_room != 0)
		clean_room();
	if (g_inf.w_heap)
		clean_heap(g_inf.w_heap);
	if (g_inf.w_ready)
		clean_heap(g_inf.w_ready);
	if (g_inf.connect)
		clean_connect(g_inf.connect, g_inf.c_room);
	if (g_inf.vis)
		free(g_inf.vis);
	if (g_inf.lines)
		free(g_inf.lines);
	if (g_inf.c_sample > 0)
		clean_sample();
	if (str)
		ft_printf("%s\n", str);
	if (i == 1)
		exit(1);
}
