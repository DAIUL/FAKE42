/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:52 by qpuig             #+#    #+#             */
/*   Updated: 2023/08/09 18:54:16 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_posr(t_mlx *mlx, int nb)
{
	int	y;
	int	x;
	int	i;

	mlx->nbrats = ft_calloc((nb + 1), sizeof(t_rats));
	y = 0;
	x = 0;
	i = 0;
	while (mlx->map[y][0])
	{
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'R')
			{
				mlx->nbrats[i].yr = y;
				mlx->nbrats[i].xr = x; 
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_enemiesmvmt(t_mlx *mlx, t_rats *rats, int yr, int xr)
{
	if (mlx->map[rats->yr + yr][rats->xr + xr] == '1'
		|| mlx->map[rats->yr + yr][rats->xr + xr] == 'C'
		|| mlx->map[rats->yr + yr][rats->xr + xr] == 'E'
		|| mlx->map[rats->yr + yr][rats->xr + xr] == 'R') 
		return ;
	mlx->map[rats->yr][rats->xr] = '0';
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->sprites[5].pointer,
		(rats->xr * 64), (rats->yr * 64));
	if (mlx->map[rats->yr + yr][rats->xr + xr] == 'P')
	{
		rats->xr += xr;
		rats->yr += yr;
		mlx->map[rats->yr][rats->xr] = 'R';
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window,
			mlx->sprites[9].pointer, (rats->xr * 64), (rats ->yr * 64));
		mlx->stop = 1;
		return ;
	}
	rats->xr += xr;
	rats->yr += yr;
	mlx->map[rats->yr][rats->xr] = 'R';
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window,
		mlx->sprites[9].pointer, (rats->xr * 64), (rats ->yr * 64));
}

void	ft_enemies(t_mlx *mlx)
{
	int	r;
	int	i;

	i = 0;
	if (!mlx->nbrats[0].xr)
		return ;
	while (mlx->nbrats[i].xr)
	{
		r = rand() % 5;
		if (r == 0)
			ft_enemiesmvmt(mlx, &mlx->nbrats[i], 0, 0);
		else if (r == 1)
			ft_enemiesmvmt(mlx, &mlx->nbrats[i], 0, -1);
		else if (r == 2)
			ft_enemiesmvmt(mlx, &mlx->nbrats[i], 1, 0);
		else if (r == 3)
			ft_enemiesmvmt(mlx, &mlx->nbrats[i], 0, 1);
		else if (r == 4)
			ft_enemiesmvmt(mlx, &mlx->nbrats[i], -1, 0);
		i++;
	}
}

void	ft_animr(t_mlx *mlx, int r)
{
	int	i;

	i = 0;
	while (mlx->nbrats[i].xr)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window,
			mlx->sprites[r].pointer, (mlx->nbrats[i].xr * 64),
			(mlx->nbrats[i].yr * 64));
		i++;
	}
}

void	ft_nbrats(t_mlx *mlx)
{
	int	nb;
	int	y;
	int	x;

	nb = 0;
	y = 0;
	x = 0;
	while (mlx->map[y][0])
	{
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'R')
				nb++;
			x++;
		}
		x = 0;
		y++;
	}
	ft_posr(mlx, nb);
}
