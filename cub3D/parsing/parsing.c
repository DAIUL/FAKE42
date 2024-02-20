/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:58:54 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/20 11:20:08 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file_len(t_txt *txt, char *map)
{
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_fd(txt);
	line = get_next_line(fd);
	txt->flen = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		txt->flen++;
	}
	free(line);
	close(fd);
	return ;
}

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
			return (close(fd), error_dir(line, txt, 2), 0);
		free(line);
		line = get_next_line(fd);
		txt->map_line++;
	}
	while ((txt->map_line + 1) < txt->flen && skip_till_elem(line) == 1)
	{
		free(line);
		line = get_next_line(fd);
		txt->map_line++;
	}
	return (free(line), close(fd), 1);
}

int	check_map_viable(char *map)
{
	t_txt	*txt;

	txt = ft_calloc(1, sizeof(t_txt));
	txt->txt = ft_calloc(7, sizeof(char *));
	txt->ray = ft_calloc(1, sizeof(t_ray));
	file_len(txt, map);
	start_to_map(map, txt);
	txt->start = 0;
	txt->fmap = map_size(map, txt);
	check_map_line(txt->fmap, txt);
	if (!try_texture(txt))
		error_map(txt, 3);
	check_line_vert(txt->fmap, txt);
	if (txt->start != 1)
		error_map(txt, 2);
	main_draw(txt);
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
