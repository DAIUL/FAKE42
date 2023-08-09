/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:04:55 by qpuig             #+#    #+#             */
/*   Updated: 2023/08/09 20:32:26 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mover(int x, int y, t_mlx *mlx, t_pos pos)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window,
		mlx->sprites[9].pointer, ((pos.x + x) * 64), ((pos.y + y) * 64));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window,
		mlx->sprites[5].pointer, (pos.x * 64), (pos.y * 64));
	ft_counter(mlx, 0);
	mlx->step++;
	ft_counter(mlx, 111111111);
	mlx->stop = 1;
}

void	ft_movee0(int x, int y, t_mlx *mlx, t_pos pos)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window,
		mlx->sprites[8].pointer, ((pos.x + x) * 64), ((pos.y + y) * 64));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window,
		mlx->sprites[5].pointer, (pos.x * 64), (pos.y * 64));
	ft_counter(mlx, 0);
	mlx->step++;
	ft_counter(mlx, 111111111);
	mlx->stop = 1;
}

void	ft_movethefinal(int x, int y, t_mlx *mlx, t_pos pos)
{
	mlx->map[pos.y][pos.x] = '0';
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window,
		mlx->sprites[5].pointer, (pos.x * 64), (pos.y * 64));
	pos.x = pos.x + x;
	pos.y = pos.y + y;
	mlx->map[pos.y][pos.x] = 'P';
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window,
		mlx->sprites[0].pointer, (pos.x * 64), (pos.y * 64));
	ft_counter(mlx, 0);
	mlx->step++;
	ft_counter(mlx, 111111111);
	ft_enemies(mlx);
}

void	ft_movec(int x, int y, t_mlx *mlx, t_pos pos)
{
	if (mlx->map[pos.y + y][pos.x + x] == 'C')
		mlx->tcollect--;
}

void	ft_move(int x, int y, t_mlx *mlx)
{
	t_pos	pos;

	pos = ft_pos(mlx->map);
	if (mlx->map[pos.y + y][pos.x + x] == '1')
	{
		ft_enemies(mlx);
		return ;
	}
	ft_movec(x, y, mlx, pos);
	if (mlx->map[pos.y + y][pos.x + x] == 'E' && mlx->tcollect == 0)
	{
		ft_movee0(x, y, mlx, pos);
		return ;
	}
	else if (mlx->map[pos.y + y][pos.x + x] == 'E' && mlx->tcollect != 0)
	{
		ft_enemies(mlx);
		return ;
	}
	else if (mlx->map[pos.y + y][pos.x + x] == 'R')
	{
		ft_mover(x, y, mlx, pos);
		return ;
	}
	ft_movethefinal(x, y, mlx, pos);
}
