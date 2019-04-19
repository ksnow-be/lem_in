/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:00:33 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/04/15 19:31:24 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			detect_iter(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_inf.iter)
	{
		j = 0;
		while (g_inf.move[i][j].operations == 1488)
		{
			if (g_inf.move[i][j].x_dst !=
					g_inf.ants[g_inf.move[i][j].num_ant - 1].x)
				return (i);
			if (g_inf.move[i][j].y_dst !=
					g_inf.ants[g_inf.move[i][j].num_ant - 1].y)
				return (i);
			j++;
		}
		i++;
	}
	return (1488);
}

int			check_algo(int tmp)
{
	int	i;
	int	j;

	i = tmp;
	j = 0;
	while (g_inf.move[i][j].operations == 1488)
	{
		if (g_inf.move[i][j].x_dst !=
				g_inf.ants[g_inf.move[i][j].num_ant - 1].x)
			return (0);
		if (g_inf.move[i][j].y_dst !=
				g_inf.ants[g_inf.move[i][j].num_ant - 1].y)
			return (0);
		j++;
	}
	return (1);
}

int			need_to_move(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_inf.iter)
	{
		j = 0;
		while (g_inf.move[i][j].operations == 1488)
		{
			if (g_inf.move[i][j].x_dst !=
					g_inf.ants[g_inf.move[i][j].num_ant - 1].x)
				return (1);
			if (g_inf.move[i][j].y_dst !=
					g_inf.ants[g_inf.move[i][j].num_ant - 1].y)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_ant		same_y(t_ant tmp, int x2, int y2)
{
	t_ant	res;

	res = tmp;
	if (res.x < x2)
		res.x++;
	else if (res.x > x2)
		res.x--;
	return (res);
}

t_ant		same_x(t_ant tmp, int x2, int y2)
{
	t_ant	res;

	res = tmp;
	if (res.y < y2)
		res.y++;
	else if (res.y > y2)
		res.y--;
	return (res);
}
