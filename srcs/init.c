/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:15:50 by vferry            #+#    #+#             */
/*   Updated: 2019/04/17 15:33:54 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	null_maker(void)
{
	g_inf.w_heap = NULL;
	g_inf.w_ready = NULL;
	g_inf.connect = NULL;
}

void	init(void)
{
	int	i;

	i = 0;
	g_inf.c_ant = 0;
	g_inf.c_room = 0;
	g_inf.r_start = -1;
	g_inf.r_end = -1;
	g_inf.c_ways = 0;
	g_inf.count_ways = 0;
	g_inf.num_ants = 1;
	g_inf.c_sample = 0;
	g_inf.sam = -1;
	g_inf.v = 0;
	g_inf.iter = 0;
	g_inf.antgo = 0;
	g_inf.what_bmp = 0;
	g_inf.flag = 0;
	null_maker();
	while (i < ROOM)
	{
		g_inf.tail[i] = -1;
		g_inf.rooms[i].name = NULL;
		i++;
	}
}

void	back_and_in(void)
{
	int	i;

	i = 0;
	g_inf.vis->win = SDL_CreateWindow("Lem_in",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	g_inf.vis->ren = SDL_CreateRenderer(g_inf.vis->win,
			-1, SDL_RENDERER_ACCELERATED);
	create_textures();
	while (i < g_inf.c_ant)
	{
		g_inf.ants[i].num = i + 1;
		g_inf.ants[i].x = g_inf.rooms[0].x;
		g_inf.ants[i].y = g_inf.rooms[0].y;
		i++;
	}
}

void	create_textures(void)
{
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/lol.bmp");
	g_inf.vis->back = SDL_CreateTextureFromSurface(g_inf.vis->ren,
			g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	if (g_inf.what_bmp == 0)
		def();
	else if (g_inf.what_bmp == 1)
		bmw();
	else if (g_inf.what_bmp == 2)
		coal();
	else if (g_inf.what_bmp == 3)
		milo();
}
