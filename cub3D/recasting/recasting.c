/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:12:59 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/18 22:24:17 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_ray(t_txt *txt)
{
	int	x;

	x = 0;
	txt->ray->planeX = 0;
	txt->ray->planeY = 0.66;
	txt->ray->time = 0;
	txt->ray->oldTime = 0;
	while (x < screenWidth)
	{
		raycasting(txt);
		setup_sidedist(txt);
		setup_hit(txt);
		setup_draw(txt);
		x++;
	}
}

void	main_draw(t_txt *txt)
{
	txt->mlx_ptr = mlx_init();
	txt->window = mlx_new_window(txt->mlx_ptr, screenWidth, screenHeight, "cub3d");
	setup_ray(txt);
	mlx_loop(txt->mlx_ptr);
}

static int	tex_num(t_txt *txt)
{
	if (txt->ray->side == 0)
	{
		if (txt->ray->raydirX < 0)
			return (0);
		else
			return (2);
	}
	else
	{
		if (txt->ray->raydirY > 0)
			return (3);
		else
			return (1);
	}
	return (0);
}