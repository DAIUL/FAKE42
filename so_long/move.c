/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:04:55 by qpuig             #+#    #+#             */
/*   Updated: 2023/07/07 17:48:36 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	jab_jab_hook(int keycode, t_mlx *mlx)
{
	ft_printf("%i\n", keycode);
	(void)mlx;
	if (keycode == 65307)
	{
		ft_freesl(mlx);
		exit(0);
	}
	if (mlx->stop == 1)
		return (0);
	if (keycode == 119 || keycode == 65362)
		ft_move(0, -1, mlx);
	else if (keycode == 97 || keycode == 65361)
		ft_move(-1, 0, mlx);
	else if (keycode == 115 || keycode == 65364)
		ft_move(0, 1, mlx);
	else if (keycode == 100 || keycode == 65363)
		ft_move(1, 0, mlx);
	return (0);
}

void	ft_move(int x, int y, t_mlx *mlx)
{
	t_pos	pos;

	pos = ft_pos(mlx->map);
	if (mlx->map[pos.y + y][pos.x + x] == '1')
	{
		ft_enemies(mlx);
		return;
	}
	else if (mlx->map[pos.y + y][pos.x + x] == 'C')
		mlx->tcollect--;
	else if (mlx->map[pos.y + y][pos.x + x] == 'E' && mlx->tcollect == 0)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->sprites[8].pointer, ((pos.x + x) * 64), ((pos.y + y) * 64));
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->sprites[5].pointer, (pos.x * 64), (pos.y * 64));
		mlx->stop = 1;
		return;
	}
	else if (mlx->map[pos.y + y][pos.x + x] == 'R')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->sprites[9].pointer, ((pos.x + x) * 64), ((pos.y + y) * 64));
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->sprites[5].pointer, (pos.x * 64), (pos.y * 64));
		mlx->stop = 1;
		return;
	}
	mlx->map[pos.y][pos.x] = '0';
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->sprites[5].pointer, (pos.x * 64), (pos.y * 64));
	pos.x = pos.x + x;
	pos.y = pos.y + y;
	mlx->map[pos.y][pos.x] = 'P';
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->sprites[0].pointer, (pos.x * 64), (pos.y * 64));
	ft_enemies(mlx);
}

int	ft_anim(t_mlx *mlx)
{
	static int	i = 0;
	static int	r = 9;
	static int	delay = 0;
	t_pos	pos;

	if (mlx->stop == 1)
		return (0);
	if (delay == 3000)
	{
		pos = ft_pos(mlx->map);
		if (i == 4 || r == 12)
		{
			i = 0;
			r = 9;
		}
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->sprites[i].pointer, (pos.x * 64), (pos.y * 64));
		ft_animr(mlx, r);
		i++;
		r++;
		delay = 0;
	}
	delay++;
	return (0);
}