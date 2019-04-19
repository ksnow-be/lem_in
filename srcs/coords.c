/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:03:38 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/04/15 19:34:46 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant		deal_coords(t_ant tmp, int x2, int y2)
{
	t_ant	res;

	res = tmp;
	res.shagx = 1;
	res.shagy = 1;
	if (abs(res.diffy) > abs(res.diffx))
		res.shagy = abs(res.diffy) / abs(res.diffx);
	else if (abs(res.diffy) < abs(res.diffx))
		res.shagx = abs(res.diffx) / abs(res.diffy);
	if (res.x > x2)
		res.shagx *= -1;
	if (res.y > y2)
		res.shagy *= -1;
	usleep(1000);
	res.x += res.shagx;
	res.y += res.shagy;
	return (res);
}

t_ant		change_coords(t_ant tmp, int x2, int y2)
{
	t_ant	res;

	res = tmp;
	res.diffx = abs(res.x - x2);
	res.diffy = abs(res.y - y2);
	if (!res.diffy)
		res = same_y(res, x2, y2);
	else if (!res.diffx)
		res = same_x(res, x2, y2);
	else
		res = deal_coords(res, x2, y2);
	return (res);
}

void		start_move_ants(int iter)
{
	int	j;

	j = 0;
	while (g_inf.move[iter][j].operations == 1488)
	{
		if (g_inf.move[iter][j].x_dst !=
				g_inf.ants[g_inf.move[iter][j].num_ant - 1].x
				|| g_inf.move[iter][j].y_dst !=
				g_inf.ants[g_inf.move[iter][j].num_ant - 1].y)
		{
			g_inf.ants[g_inf.move[iter][j].num_ant - 1] =
				change_coords(g_inf.ants[g_inf.move[iter][j].num_ant - 1],
				g_inf.move[iter][j].x_dst,
				g_inf.move[iter][j].y_dst);
		}
		j++;
	}
}
