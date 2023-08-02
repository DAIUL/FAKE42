/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:20:31 by qpuig             #+#    #+#             */
/*   Updated: 2023/05/26 19:04:56 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_failure(t_mlx *mlx, char *message)
{
	ft_printf("%s\n", message);
	ft_freesl(mlx);
	exit(EXIT_FAILURE);
}

char	**ft_remove(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y][0])
	{
		x = 0;
		while (map[y][x] != '\n')
			x++;
		if (map[y][x] == '\n')
		{
			map[y][x] = '\0';
			y++;
		}
	}
	return (map);
}

char	**ft_map(int argc, char **argv)
{
	int	fd;
	char	**map;
	char	*book;
	int	lect;
	int	i;

	if (argc != 2)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	lect = 0;
	book = get_next_line(fd);
	while (book)
	{
		free(book);
		book = get_next_line(fd);
		lect++;
	}
	free(book);
	map = ft_calloc((lect + 1) , sizeof(char *));
	close(fd);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i < lect)
		map[i++] = get_next_line(fd);
	close(fd);
	map[i] = ft_calloc(sizeof(char), 1);
	ft_remove(map);
	return(map);
}

void	ft_display(char **map, t_mlx mlx)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y][0])
	{
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.window, mlx.sprites[4].pointer, (x * 64), (y * 64));
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.window, mlx.sprites[0].pointer, (x * 64), (y * 64));
			else if (map[y][x] == '0')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.window, mlx.sprites[5].pointer, (x * 64), (y * 64));
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.window, mlx.sprites[7].pointer, (x * 64), (y * 64));
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.window, mlx.sprites[6].pointer, (x * 64), (y * 64));
			else if (map[y][x] == 'R')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.window, mlx.sprites[9].pointer, (x * 64), (y * 64));
			x++;
		}
		x = 0;
		y++;
		
	}
	return;
}