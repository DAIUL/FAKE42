/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:40:39 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/20 11:24:11 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_txt *txt, int x)
{
	txt->ray->camera_x = 2 * x / (double)screenWidth - 1;
	txt->ray->ray_dir_x = txt->ray->dir_x
		+ txt->ray->plane_x * txt->ray->camera_x;
	txt->ray->ray_dir_y = txt->ray->dir_y
		+ txt->ray->plane_y * txt->ray->camera_x;
	txt->ray->map_x = (int)txt->ray->pos_x;
	txt->ray->map_y = (int)txt->ray->pos_y;
	txt->ray->delta_dist_x = fabs(1 / txt->ray->ray_dir_x);
	txt->ray->delta_dist_y = fabs(1 / txt->ray->ray_dir_y);
	txt->ray->hit = 0;
}

void	ft_free_buffer(t_txt *txt)
{
	int	y;

	y = 0;
	if (txt->buffer)
	{
		while (y < screenHeight)
		{
			free(txt->buffer[y]);
			y++;
		}
		free(txt->buffer);
	}
}
