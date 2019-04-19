/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:54:19 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/04/15 19:37:33 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lines		*correct_line(void)
{
	if (g_inf.lines->x1 < g_inf.lines->x2)
		var1();
	else if (g_inf.lines->x1 > g_inf.lines->x2)
		var2();
	else
		var3();
	return (g_inf.lines);
}

void		var1(void)
{
	if (g_inf.lines->y1 < g_inf.lines->y2)
	{
		g_inf.lines->x1 += SPRITE_SIZE / 2;
		g_inf.lines->y1 += SPRITE_SIZE;
		g_inf.lines->x2 += SPRITE_SIZE / 2;
	}
	else if (g_inf.lines->y1 > g_inf.lines->y2)
	{
		g_inf.lines->x1 += SPRITE_SIZE / 2;
		g_inf.lines->x2 += SPRITE_SIZE / 2;
		g_inf.lines->y2 += SPRITE_SIZE;
	}
	else
	{
		g_inf.lines->x1 += SPRITE_SIZE;
		g_inf.lines->y1 += SPRITE_SIZE / 2;
		g_inf.lines->y2 += SPRITE_SIZE / 2;
	}
}

void		var2(void)
{
	if (g_inf.lines->y1 < g_inf.lines->y2)
	{
		g_inf.lines->y1 += SPRITE_SIZE;
		g_inf.lines->x1 += SPRITE_SIZE / 2;
		g_inf.lines->x2 += SPRITE_SIZE / 2;
	}
	else if (g_inf.lines->y1 > g_inf.lines->y2)
	{
		g_inf.lines->x2 += SPRITE_SIZE / 2;
		g_inf.lines->x1 += SPRITE_SIZE / 2;
		g_inf.lines->y2 += SPRITE_SIZE;
	}
	else
	{
		g_inf.lines->x2 += SPRITE_SIZE;
		g_inf.lines->y1 += SPRITE_SIZE / 2;
		g_inf.lines->y2 += SPRITE_SIZE / 2;
	}
}

void		var3(void)
{
	if (g_inf.lines->y1 < g_inf.lines->y2)
	{
		g_inf.lines->y1 += SPRITE_SIZE;
		g_inf.lines->x1 += SPRITE_SIZE / 2;
		g_inf.lines->x2 += SPRITE_SIZE / 2;
	}
	else if (g_inf.lines->y1 > g_inf.lines->y2)
	{
		g_inf.lines->x1 += SPRITE_SIZE / 2;
		g_inf.lines->x2 += SPRITE_SIZE / 2;
		g_inf.lines->y2 += SPRITE_SIZE;
	}
}

int			abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
