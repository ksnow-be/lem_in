/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:21:40 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/04/17 14:32:48 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		close_sdl(void)
{
	SDL_DestroyTexture(g_inf.vis->ant);
	SDL_DestroyTexture(g_inf.vis->ant2);
	SDL_DestroyTexture(g_inf.vis->back);
	SDL_DestroyTexture(g_inf.vis->flag);
	SDL_DestroyTexture(g_inf.vis->flag_fin);
	SDL_DestroyRenderer(g_inf.vis->ren);
	SDL_DestroyWindow(g_inf.vis->win);
	SDL_Quit();
}

void		vizu(void)
{
	back_and_in();
	while (g_inf.vis->gameover)
	{
		if (SDL_PollEvent(&g_inf.vis->event))
		{
			if (g_inf.vis->event.type == SDL_QUIT)
				g_inf.vis->gameover = 0;
			if (g_inf.vis->event.type == SDL_KEYDOWN &&
					g_inf.vis->event.key.keysym.sym == SDLK_ESCAPE)
				g_inf.vis->gameover = 0;
			if (g_inf.vis->event.type == SDL_KEYDOWN &&
					g_inf.vis->event.key.keysym.sym == SDLK_SPACE)
				g_inf.vis->gameover = 0;
		}
		draw_rooms();
		draw_lines();
		draw_ants();
		move_ant();
		SDL_RenderPresent(g_inf.vis->ren);
		SDL_RenderCopy(g_inf.vis->ren, g_inf.vis->back, NULL, NULL);
	}
	close_sdl();
}
