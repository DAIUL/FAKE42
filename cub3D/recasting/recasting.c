/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:12:59 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/14 12:22:21 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_display2(char **map, t_txt *txt, int x, int y)
{
	if (map[y][x] == '0')
		mlx_pixel_put(txt->mlx_ptr,
					txt->window, (x * 64), (y * 64), 0x000000);
}

void	ft_display(char **map, t_txt *txt)
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
				mlx_pixel_put(txt->mlx_ptr,
					txt->window, (x * 64), (y * 64), 0xC8C8C8);
			else
				ft_display2(map, txt, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void	main_draw(t_txt *txt)
{
	txt->mlx_ptr = mlx_init();
	txt->window = mlx_new_window(txt->mlx_ptr, 1024, 512, "cub3d");
	ft_display(txt->txt, txt);
	mlx_loop(txt->mlx_ptr);
}