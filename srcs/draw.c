/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:57:27 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/04/16 13:35:29 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		draw_rooms(void)
{
	int	i;

	i = 0;
	while (g_inf.rooms[i].name)
	{
		g_inf.vis->rcbeg.x = g_inf.rooms[i].x;
		g_inf.vis->rcbeg.y = g_inf.rooms[i].y;
		g_inf.vis->rcbeg.w = SPRITE_SIZE;
		g_inf.vis->rcbeg.h = SPRITE_SIZE;
		if (!g_inf.rooms[i].s_or_e)
			SDL_RenderCopy(g_inf.vis->ren,
					g_inf.vis->flag, NULL, &g_inf.vis->rcbeg);
		else
			SDL_RenderCopy(g_inf.vis->ren,
					g_inf.vis->flag_fin, NULL, &g_inf.vis->rcbeg);
		i++;
	}
}

void		draw_lines(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_inf.c_room)
	{
		j = 0;
		while (j < g_inf.c_room)
		{
			if (g_inf.connect[i][j])
				start_draw_line(i, j);
			j++;
		}
		i++;
	}
}

void		draw_ants(void)
{
	int	i;

	i = 0;
	g_inf.vis->rcbeg.w = SPRITE_SIZE;
	g_inf.vis->rcbeg.h = SPRITE_SIZE;
	while (i < g_inf.c_ant)
	{
		g_inf.vis->rcbeg.x = g_inf.ants[i].x;
		g_inf.vis->rcbeg.y = g_inf.ants[i].y;
		if (i % 2)
			SDL_RenderCopy(g_inf.vis->ren,
					g_inf.vis->ant2, NULL, &g_inf.vis->rcbeg);
		else
			SDL_RenderCopy(g_inf.vis->ren,
					g_inf.vis->ant, NULL, &g_inf.vis->rcbeg);
		i++;
	}
}

void		start_draw_line(int i, int j)
{
	g_inf.lines->x1 = g_inf.rooms[i].x;
	g_inf.lines->y1 = g_inf.rooms[i].y;
	g_inf.lines->x2 = g_inf.rooms[j].x;
	g_inf.lines->y2 = g_inf.rooms[j].y;
	g_inf.lines = correct_line();
	thickLineRGBA(g_inf.vis->ren, g_inf.lines->x1,
			g_inf.lines->y1, g_inf.lines->x2,
			g_inf.lines->y2, 2, 140, 140, 140, 200);
}

void		move_ant(void)
{
	static int	i;

	if (!i)
		i = 0;
	if (need_to_move())
	{
		if (i > g_inf.iter)
			return ;
		start_move_ants(i);
		if (check_algo(i))
		{
			i++;
			usleep(100000);
		}
	}
	else
		return ;
}
