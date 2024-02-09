/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:58:42 by qpuig             #+#    #+#             */
/*   Updated: 2024/01/27 16:58:42 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*remove_nl(char *line, t_txt *txt)
{
	int	i;
	char	*clear;

	i = 0;
	clear = ft_calloc(txt->max_len, sizeof(char));
	while (line[i] && (line[i] != '\n'))
	{
		clear[i] = line[i];
		i++;
	}
	while (i < ((int)txt->max_len - 1))
	{
		clear[i] = ' ';
		i++;
	}
	free(line);
	return (clear);
}

char	**copy_map(char **map, t_txt *txt, char *premap)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(premap, O_RDONLY);
	if (fd < 0)
		error_fd(txt);
	line = get_next_line(fd);
	while (line && txt->map_line > 2)
	{
		free(line);
		line = get_next_line(fd);
		txt->map_line--;
	}
	free(line);
	i = 0;
	while (i < ((int)txt->lect - 1))
	{
		line = get_next_line(fd);
		map[i++] = remove_nl(line, txt);
	}
	return (close(fd), map);
}

char	*map_size_2(t_txt *txt, int fd)
{
	char	*line;

	txt->lect = txt->map_line;
	line = get_next_line(fd);
	while (line && txt->lect > 1)
	{
		free(line);
		line = get_next_line(fd);
		txt->lect--;
	}
	txt->max_len = ft_strlen(line);
	return (line);
}

char	**map_size(char *premap, t_txt *txt)
{
	char	**map;
	int		fd;
	char	*line;

	fd = open(premap, O_RDONLY);
	if (fd < 0)
		error_fd(txt);
	line = map_size_2(txt, fd);
	while (line && map_line_v(line, txt) == 1)
	{
		free(line);
		line = get_next_line(fd);
		if (line && ft_strlen(line) > txt->max_len)
			txt->max_len = ft_strlen(line);
		txt->lect++;
	}
	free(line);
	map = ft_calloc((txt->lect + 1), sizeof(char *));
	close(fd);
	map = copy_map(map, txt, premap);
	return (map);
}