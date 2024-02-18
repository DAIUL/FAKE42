/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:57:37 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/18 17:48:14 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	mv_left(t_txt *txt)
{
	if (txt->fmap[(int)(txt->ray->posX - txt->ray->dirY * MS)][(int)(txt->ray->posY)] == '0')
		txt->ray->posX -= txt->ray->dirY * MS;
	if (txt->fmap[(int)(txt->ray->posX)][(int)(txt->ray->posY + txt->ray->dirX * MS)] == '0')
		txt->ray->posY += txt->ray->dirX * MS;
	txt->mv = 1;
}

void	mv_right(t_txt *txt)
{
	if (txt->fmap[(int)(txt->ray->posX + txt->ray->dirY * MS)][(int)(txt->ray->posY)] == '0')
		txt->ray->posX += txt->ray->dirY * MS;
	if (txt->fmap[(int)(txt->ray->posX)][(int)(txt->ray->posY - txt->ray->dirX * MS)] == '0')
		txt->ray->posY -= txt->ray->dirX * MS;
	txt->mv = 1;
}

void	rot_cam(t_txt *txt, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;
	
	oldDirX = txt->ray->dirX;
	oldPlaneX = txt->ray->planeX;
	txt->ray->dirX = txt->ray->dirX * cos(rotSpeed) - txt->ray->dirY * sin(rotSpeed);
	txt->ray->dirY = oldDirX * sin(rotSpeed) + txt->ray->dirY * cos(rotSpeed);
	txt->ray->planeX = txt->ray->planeX * cos(rotSpeed) - txt->ray->planeY * sin(rotSpeed);
	txt->ray->planeY = oldPlaneX * sin(rotSpeed) + txt->ray->planeY * cos(rotSpeed);
	txt->mv = 1;
}

void	act_move(t_txt *txt)
{
	if (keycode == ESC)
		free_end(txt);
	if (txt->forw == 1)
		mv_forw(txt);
	if (txt->back == 1)
		mv_back(txt);
	if (txt->left = 1)
		mv_left(txt);
	if (txt->right = 1)
		mv_right(txt);
	if (txt->cleft == 1)
		rot_cam(txt, RS);
	if (txt->cright == 1)
		rot_cam(txt, -RS);
	if (txt->mv == 1)
		setup_ray(txt);
}