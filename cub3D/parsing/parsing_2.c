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

int	check_dir_line(char *s, t_txt *txt)
{
	int	i;

	if ((ft_strncmp(s, "NO ", 3) == 0))
		fill_txt(s, NO, txt);
	else if (ft_strncmp(s, "SO ", 3) == 0)
		fill_txt(s, SO, txt);
	else if (ft_strncmp(s, "EA ", 3) == 0)
		fill_txt(s, EA, txt);
	else if (ft_strncmp(s, "WE ", 3) == 0)
		fill_txt(s, WE, txt);
	else if (ft_strncmp(s, "C ", 2) == 0)
	 	fill_txt(s, C, txt);
	 else if (ft_strncmp(s, "F ", 2) == 0)
	 	fill_txt(s, F, txt);
	else
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '1' || s[i] == '0' || s[i] == 'N'
				|| s[i] == 'E' || s[i] == 'W' || s[i++] == 'S')
				return (ft_printf("map pas au bon endroit\n"), 0);
		}
	}
	return (1);
}

int	check_map_line(char **s, t_txt *txt)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == ' ' && (s[i][j + 1] != ' ' || s[i][j + 1] != '1'))
				return (ft_printf("map ouverte\n"), 0);
			if ((s[i][j] == 'N' || s[i][j] == 'E' || s[i][j] == 'W' || s[i][j] == 'S')
				&& (s[i][j + 1] == '0' || s[i][j + 1] == '1'))
				txt->start += 1;
			if ((s[i][j] == 'N' || s[i][j] == 'E' || s[i][j] == 'W' || s[i][j] == 'S')
				&& (s[i][j + 1] != '0' || s[i][j + 1] != '1'))
				return (ft_printf("map ouverte\n"), 0);
			if (s[i][j] == '0'
				&& (s[i][j + 1] != 'N' || s[i][j + 1] != 'E' || s[i][j + 1] != 'W' || s[i][j + 1] != 'S'))
				return (ft_printf("map ouverte\n"), 0);
			j++;
		}
		if (txt->start > 1)
			return (ft_printf("trop de positions de depart\n"), 0);
		i++;
	}
	return (1);
}

char	*remove_nl(char *line)
{
	int	i;
	char	*clear;

	i = 0;
	clear = ft_calloc(ft_strlen(line), sizeof(char));
	while (line[i] && (line[i] != '\n'))
	{
		clear[i] = line[i];
		i++;
	}
	free(line);
	return (clear);
}

char	**copy_map(char **map, int lect, char *premap, int map_line)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(premap, O_RDONLY);
	line = get_next_line(fd);
	while (line && map_line > 1)
	{
		free(line);
		line = get_next_line(fd);
		map_line--;
	}
	while (i < (lect - 1))
	{
		line = get_next_line(fd);
		map[i++] = remove_nl(line);
	}
	close(fd);
	return (map);
}

char	**map_size(char *premap, int map_line)
{
	char	**map;
	int		lect;
	int		fd;
	char	*line;

	fd = open(premap, O_RDONLY);
	//if (fd < 0)
	//	ERROR
	lect = map_line;
	line = get_next_line(fd);
	while (line && lect > 0)
	{
		free(line);
		line = get_next_line(fd);
		lect--;
	}
	while (line && map_line_v(line) == 1)
	{
		free(line);
		line = get_next_line(fd);
		lect++;
	}
	free(line);
	map = ft_calloc((lect + 1), sizeof(char *));
	close(fd);
	map = copy_map(map, lect, premap, map_line);
	return (map);
}