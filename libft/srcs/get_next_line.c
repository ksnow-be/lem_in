/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:32:09 by vferry            #+#    #+#             */
/*   Updated: 2018/12/08 18:32:13 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char	*ft_zapic(char **str, char *buff)
{
	char	*perezap;

	if (*str == NULL)
	{
		if (!(*str = (char*)malloc(1)))
			return (NULL);
		*str[0] = '\0';
	}
	perezap = ft_strjoin(*str, buff);
	free(*str);
	*str = NULL;
	return (perezap);
}

static void	ft_perezapic(char **str, char **line)
{
	char	*mem;
	char	*buf;
	int		i;

	i = 0;
	if ((buf = ft_strchr(*str, '\n')) == NULL)
		buf = ft_strchr(*str, '\0');
	if (*buf == '\n')
	{
		*buf = '\0';
		buf++;
	}
	*line = ft_strdup(*str);
	mem = (char*)malloc(sizeof(char) * ft_strlen(buf) + 1);
	mem = ft_strcpy(mem, buf);
	free(*str);
	*str = mem;
}

int			get_next_line(const int fd, char **line)
{
	static char		*list[2147483647];
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*buf;

	if ((fd < 0) || ((ret = read(fd, 0, 0)) == -1))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		buf = list[fd];
		if ((list[fd] = ft_zapic(&buf, buff)) == NULL)
			return (-1);
		if (ft_check(buff) == 1)
			break ;
	}
	if (list[fd] == NULL || list[fd][0] == 0)
	{
		list[fd] = ft_zapic(&list[fd], "");
		ft_perezapic(&list[fd], line);
		return (0);
	}
	ft_perezapic(&list[fd], line);
	return (1);
}
