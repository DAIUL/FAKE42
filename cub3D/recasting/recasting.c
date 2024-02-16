/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:12:59 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/16 17:37:26 by qpuig            ###   ########.fr       */
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