/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:20:31 by qpuig             #+#    #+#             */
/*   Updated: 2023/08/09 20:42:25 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_remove(char *book)
{
	int		i;
	int		j;
	char	*clean;

	i = 0;
	while (book[i] && book[i] != '\n')
		i++;
	clean = ft_calloc((i + 1), sizeof(char));
	j = 0;
	while (j <= i && book[j] && book[j] != '\n')
	{
		clean[j] = book[j];
		j++;
	}
	free(book);
	return (clean);
}

char	**ft_map2(char **map, int lect, int fd, char **argv)
{
	int		i;
	char	*book;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i < lect)
	{
		book = get_next_line(fd);
		map[i++] = ft_remove(book);
	}
	close(fd);
	map[i] = ft_calloc(sizeof(char), 1);
	return (map);
}

char	**ft_map(int argc, char **argv)
{
	int		fd;
	char	**map;
	char	*book;
	int		lect;

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
	map = ft_calloc((lect + 1), sizeof(char *));
	close(fd);
	map = ft_map2(map, lect, fd, argv);
	return (map);
}

void	ft_display2(char **map, t_mlx mlx, int x, int y)
{
	if (map[y][x] == 'P')
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.window, mlx.sprites[0].pointer, (x * 64), (y * 64));
	else if (map[y][x] == '0')
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.window, mlx.sprites[5].pointer, (x * 64), (y * 64));
	else if (map[y][x] == 'E')
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.window, mlx.sprites[7].pointer, (x * 64), (y * 64));
	else if (map[y][x] == 'C')
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.window, mlx.sprites[6].pointer, (x * 64), (y * 64));
	else if (map[y][x] == 'R')
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.window, mlx.sprites[9].pointer, (x * 64), (y * 64));
	else
		ft_failure(mlx.mlx_ptr, "Connais pas");
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
				mlx_put_image_to_window(mlx.mlx_ptr,
					mlx.window, mlx.sprites[4].pointer, (x * 64), (y * 64));
			else
				ft_display2(map, mlx, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}
