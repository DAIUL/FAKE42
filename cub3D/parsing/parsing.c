/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:58:54 by qpuig             #+#    #+#             */
/*   Updated: 2024/01/27 16:58:54 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_to_map(char *map, t_txt *txt)
{
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_fd(txt);
	line = get_next_line(fd);
	txt->map_line = 1;
	while (line && (check_nb(txt) != 1))
	{
		if (check_dir_line(line, txt) == 0)
			return (close(fd), error_dir(line, txt), 0);
		free(line);
		line = get_next_line(fd);
		txt->map_line++;
	}
	while (skip_till_elem(line) == 1)
	{
		free(line);
		line = get_next_line(fd);
		txt->map_line++;
	}
	free(line);
	close(fd);
	return (1);
}

int	check_map_viable(char *map)
{
	char	**fmap;
	t_txt	*txt;

	txt = ft_calloc(1, sizeof(t_txt));
	txt->txt = ft_calloc(7, sizeof(char *));
	start_to_map(map, txt);
	txt->start = 0;
	fmap = map_size(map, txt);
	check_map_line(fmap, txt);
	check_line_vert(fmap, txt);
	ft_printf("youpi\n");
	return (1);
}

int	parsing_map(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i -= 4;
	if ((map[i] == '.') && (map[i + 1] == 'c')
		&& (map[i + 2] == 'u') && (map[i + 3] == 'b'))
		check_map_viable(map);
	else
		return (printf("Map au mauvais format\n"), 0);
	return (1);
}