/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:12:11 by qpuig             #+#    #+#             */
/*   Updated: 2023/08/09 20:15:32 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_counter(t_mlx *mlx, int color)
{
	char	*steps;

	steps = ft_itoa(mlx->step);
	mlx_string_put(mlx->mlx_ptr, mlx->window,
		((mlx->lenx / 2) * 64), ((mlx->leny * 64) + 15), color, steps);
	free(steps);
}

int	jab_jab_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 65307)
	{
		ft_freesl(mlx);
		exit(0);
	}
	if (mlx->stop == 1)
		return (0);
	else if (keycode == 119 || keycode == 65362)
		ft_move(0, -1, mlx);
	else if (keycode == 97 || keycode == 65361)
		ft_move(-1, 0, mlx);
	else if (keycode == 115 || keycode == 65364)
		ft_move(0, 1, mlx);
	else if (keycode == 100 || keycode == 65363)
		ft_move(1, 0, mlx);
	return (0);
}

int	ft_anim(t_mlx *mlx)
{
	static int	i = 0;
	static int	r = 9;
	static int	delay = 0;
	t_pos		pos;

	if (mlx->stop == 1)
		return (0);
	if (delay == 5000)
	{
		pos = ft_pos(mlx->map);
		if (i == 4 || r == 12)
		{
			i = 0;
			r = 9;
		}
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window,
			mlx->sprites[i].pointer, (pos.x * 64), (pos.y * 64));
		ft_animr(mlx, r);
		i++;
		r++;
		delay = 0;
	}
	delay++;
	return (0);
}
