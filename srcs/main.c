/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:05:15 by vferry            #+#    #+#             */
/*   Updated: 2019/04/17 15:36:13 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	panic(void)
{
	ft_printf("\033[1m\033[32mUse only -bmw | -pure | -coal flag!\n");
	exit(1);
}

void	bmp_var(char *argv1, char *argv2)
{
	g_inf.v = 1;
	if (!ft_strcmp(argv1, "-v"))
	{
		if (!ft_strcmp(argv2, "-bmw"))
			g_inf.what_bmp = 1;
		else if (!ft_strcmp(argv2, "-coal"))
			g_inf.what_bmp = 2;
		else if (!ft_strcmp(argv2, "-pure"))
			g_inf.what_bmp = 3;
		else
			panic();
	}
	else
		return ;
}

int		main(int argc, char **argv)
{
	init();
	if (argc == 2 && !ft_strcmp(argv[1], "-v"))
		g_inf.v = 1;
	else if (argc == 3)
		bmp_var(argv[1], argv[2]);
	parsing();
	look_way();
	get_ways();
	if (g_inf.flag == 0)
	{
		pick();
		walk();
	}
	if (g_inf.v)
	{
		g_inf.vis = (t_vis*)malloc(sizeof(t_vis));
		g_inf.lines = (t_lines*)malloc(sizeof(t_lines));
		g_inf.vis->gameover = 1;
		vizu();
	}
	ft_clean(NULL, 0);
	return (0);
}
