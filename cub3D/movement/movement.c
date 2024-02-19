/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:26:06 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/18 17:39:27 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mv_forw(t_txt *txt)
{
	if(txt->fmap[int(txt->ray->pos_x + txt->ray->dir_x * MS)][int(txt->ray->pos_y)] == '0')
		txt->ray->pos_x += txt->ray->dir_x * MS;
	if(txt->fmap[int(txt->ray->pos_x)][int(txt->ray->pos_y + txt->ray->dir_y * MS)] == '0')
		txt->ray->pos_y += txt->ray->dir_y * MS;
	txt->mv = 1;
}

void	mv_back(t_txt *txt)
{
	if(txt->fmap[int(txt->ray->pos_x - txt->ray->dir_x * MS)][int(txt->ray->pos_y)] == '0') 
		txt->ray->pos_x -= txt->ray->dir_x * MS;
	if(txt->fmap[int(txt->ray->pos_x)][int(txt->ray->pos_y - txt->ray->dir_y * MS)] == '0')
		txt->ray->pos_y -= txt->ray->dir_y * MS;
	txt->mv = 1;
}

void	press_key(int keycode, t_txt *txt)
{
	if (keycode == ESC)
		free_end(txt);
	else if (keycode == W || keycode == UP)
		txt->forw = 1;
	else if (keycode == S || keycode == DOWN)
		txt->back = 1;
	else if (keycode == A)
		txt->left = 1;
	else if (keycode == D)
		txt->right = 1;
	else if (keycode == LEFT)
		txt->cleft = 1;
	else if (keycode == RIGHT)
		txt->cright = 1;
}

void	release_key(int keycode, t_game *game)
{
	if (keycode == W || keycode == UP)
		txt->forw = 0;
	else if (keycode == S || keycode == DOWN)
		txt->back = 0;
	else if (keycode == A)
		txt->left = 0;
	else if (keycode == D)
		txt->right = 0;
	else if (keycode == LEFT)
		txt->cleft = 0;
	else if (keycode == RIGHT)
		txt->cright = 0;
}