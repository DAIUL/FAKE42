/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:26:06 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/19 22:33:14 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mv_forw(t_txt *txt)
{
	if(txt->fmap[(int)(txt->ray->pos_y)][(int)(txt->ray->pos_x + txt->ray->dir_x * MS)] == '0')
		txt->ray->pos_x += txt->ray->dir_x * MS;
	if(txt->fmap[(int)(txt->ray->pos_y + txt->ray->dir_y * MS)][(int)(txt->ray->pos_x)] == '0')
		txt->ray->pos_y += txt->ray->dir_y * MS;
	txt->mv = 1;
}

void	mv_back(t_txt *txt)
{
	if(txt->fmap[(int)(txt->ray->pos_y)][(int)(txt->ray->pos_x - txt->ray->dir_x * MS)] == '0') 
		txt->ray->pos_x -= txt->ray->dir_x * MS;
	if(txt->fmap[(int)(txt->ray->pos_y - txt->ray->dir_y * MS)][(int)(txt->ray->pos_x)] == '0')
		txt->ray->pos_y -= txt->ray->dir_y * MS;
	txt->mv = 1;
}

int	press_key(int keycode, t_txt *txt)
{
	if (keycode == ESC)
		return (free_all(txt), exit(EXIT_SUCCESS), 0);
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
	return (0);
}

int	release_key(int keycode, t_txt *txt)
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
	return (0);
}