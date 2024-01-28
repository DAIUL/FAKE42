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
#include <stdio.h>

int	check_map_viable(char *map)
{
	char	*line;
	int	fd;
	int	map_line;
	t_txt	txt;

	//txt = ft_calloc(1, sizeof(t_txt));
	txt.txt = ft_calloc(7, sizeof(char *));
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	map_line = 1;
	ft_printf("%s", line);
	while (line && (check_nb(&txt) != 1))
	{
		if (check_dir_line(line, &txt) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
		map_line++;
	}
	if (check_nb(&txt) == 1)
		ft_printf("carre dans l'axe\n");
	while (skip_till_elem(line) == 1)
	{
		free(line);
		line = get_next_line(fd);
		map_line++;
	}
	txt.start = 0;
	map_size(map, &txt, map_line);
	// while (line && end_map(line) != 2)
	// {
	// 	ft_printf("%s", line);
	// 	if (check_map_line(line, &txt) == 0)
	//  	{
	//  		free(line);
	//  		return (0);
	//  	}
	//  	free(line);
	// 	line = get_next_line(fd);
	// }
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
		return (printf("non\n"), 0);
	return (1);
}