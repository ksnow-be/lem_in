/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:56:06 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/04/17 16:08:33 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	bmw(void)
{
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/x5.bmp");
	g_inf.vis->ant = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/kop.bmp");
	g_inf.vis->ant2 = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/f.bmp");
	g_inf.vis->flag = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/fin.bmp");
	g_inf.vis->flag_fin = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
}

void	coal(void)
{
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/alp.bmp");
	g_inf.vis->ant = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/kap.bmp");
	g_inf.vis->ant2 = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/flag.bmp");
	g_inf.vis->flag = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/start.bmp");
	g_inf.vis->flag_fin = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
}

void	milo(void)
{
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/alpaca.bmp");
	g_inf.vis->ant = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/cat_1.bmp");
	g_inf.vis->ant2 = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/white_ball.bmp");
	g_inf.vis->flag = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/green_ball.bmp");
	g_inf.vis->flag_fin = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
}

void	def(void)
{
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/bug.bmp");
	g_inf.vis->ant = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/bug.bmp");
	g_inf.vis->ant2 = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/house.bmp");
	g_inf.vis->flag = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
	g_inf.vis->back_tmp = SDL_LoadBMP("bmp/crown.bmp");
	g_inf.vis->flag_fin = SDL_CreateTextureFromSurface(g_inf.vis->ren,
						g_inf.vis->back_tmp);
	SDL_FreeSurface(g_inf.vis->back_tmp);
}
