/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:42:46 by vferry            #+#    #+#             */
/*   Updated: 2019/04/09 16:00:43 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	parse_ants(char *str)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (str[i])
		if (number(str[i]) == 0)
		{
			tmp += str[i] - 48;
			if (number(str[i + 1]) == 0)
				tmp *= 10;
			i++;
		}
		else
		{
			ft_strdel(&str);
			ft_clean("Not ants", 1);
		}
	ft_strdel(&str);
	if (tmp != 0)
		g_inf.c_ant = tmp;
	else
		ft_clean("Not ants", 1);
}

static void	parsing3(char *line, char c)
{
	if (c == 1)
	{
		ft_strdel(&line);
		get_next_line(0, &line);
		check_room(line);
		g_inf.r_start = g_inf.c_room;
		take_room(line, 1, 0);
	}
	else
	{
		ft_strdel(&line);
		get_next_line(0, &line);
		check_room(line);
		g_inf.r_end = g_inf.c_room;
		take_room(line, 2, 0);
	}
}

static void	parsing2(char *line)
{
	if (!line)
		return ;
	if (g_inf.connect == NULL)
		create_con();
	take_con(line);
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
			ft_strdel(&line);
		if (line && line[0] == '#' && line[1] == '#')
			ft_strdel(&line);
		if (line)
			take_con(line);
	}
	if (line)
		ft_strdel(&line);
	g_inf.tail[0] = g_inf.r_end;
	g_inf.rooms[g_inf.r_end].weight[0] = 0;
}

void		parsing(void)
{
	char	*line;

	get_next_line(0, &line);
	parse_ants(line);
	while (get_next_line(0, &line) > 0)
		if (ft_strcmp(line, "##start") == 0)
			parsing3(line, 1);
		else if (ft_strcmp(line, "##end") == 0)
			parsing3(line, 2);
		else if (line[0] == '#')
		{
			ft_strdel(&line);
			continue ;
		}
		else if (check_room(line) == 1)
			break ;
		else
			take_room(line, 0, 0);
	if (g_inf.r_end == -1 || g_inf.r_start == -1)
	{
		ft_strdel(&line);
		ft_clean("No start or end", 1);
	}
	g_inf.rooms[g_inf.r_start].ant = g_inf.c_ant;
	parsing2(line);
}
