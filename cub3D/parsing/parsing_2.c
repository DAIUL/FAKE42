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
				return (0);
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
			if (s[i][j] == ' ' && (s[i][j + 1] != ' ' && s[i][j + 1] != '1'
				&& s[i][j + 1] != '\0'))
				error_map(s, txt);
			if ((s[i][j] == 'N' || s[i][j] == 'E' || s[i][j] == 'W' || s[i][j] == 'S')
				&& (s[i][j + 1] == '0' || s[i][j + 1] == '1'))
				txt->start += 1;
			if ((s[i][j] == 'N' || s[i][j] == 'E' || s[i][j] == 'W' || s[i][j] == 'S')
				&& (s[i][j + 1] != '0' && s[i][j + 1] != '1'))
				error_map(s, txt);
 			if (s[i][j] == '0'	
				&& (s[i][j + 1] != 'N' && s[i][j + 1] != 'E' && s[i][j + 1] != 'W'
				&& s[i][j + 1] != 'S' && s[i][j + 1] != '1' && s[i][j + 1] != '0'))
				error_map(s, txt);
			j++;
		}
		if (txt->start > 1)
			return (ft_printf("trop de positions de depart\n"), 0);
		i++;
	}
	return (1);
}

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
	close(fd);
	return (map);
}

char	**map_size(char *premap, t_txt *txt)
{
	char	**map;
	int		fd;
	char	*line;

	fd = open(premap, O_RDONLY);
	if (fd < 0)
		error_fd(txt);
	txt->lect = txt->map_line;
	line = get_next_line(fd);
	while (line && txt->lect > 1)
	{
		free(line);
		line = get_next_line(fd);
		txt->lect--;
	}
	txt->max_len = ft_strlen(line);
	while (line && map_line_v(line) == 1)
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