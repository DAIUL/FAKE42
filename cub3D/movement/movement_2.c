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
	if (txt->fmap[(int)(txt->ray->pos_y)][(int)(txt->ray->pos_x - txt->ray->dir_y * MS)] == '0')
		txt->ray->pos_x -= txt->ray->dir_y * MS;
	if (txt->fmap[(int)(txt->ray->pos_y + txt->ray->dir_x * MS)][(int)(txt->ray->pos_x)] == '0')
		txt->ray->pos_y += txt->ray->dir_x * MS;
	txt->mv = 1;
}

void	mv_right(t_txt *txt)
{
	if (txt->fmap[(int)(txt->ray->pos_y)][(int)(txt->ray->pos_x + txt->ray->dir_y * MS)] == '0')
		txt->ray->pos_x += txt->ray->dir_y * MS;
	if (txt->fmap[(int)(txt->ray->pos_y - txt->ray->dir_x * MS)][(int)(txt->ray->pos_x)] == '0')
		txt->ray->pos_y -= txt->ray->dir_x * MS;
	txt->mv = 1;
}

void	rot_cam(t_txt *txt, double rot_speed)
{
	double	olddir_x;
	double	oldplane_x;
	
	olddir_x = txt->ray->dir_x;
	oldplane_x = txt->ray->plane_x;
	txt->ray->dir_x = txt->ray->dir_x * cos(rot_speed) - txt->ray->dir_y * sin(rot_speed);
	txt->ray->dir_y = olddir_x * sin(rot_speed) + txt->ray->dir_y * cos(rot_speed);
	txt->ray->plane_x = txt->ray->plane_x * cos(rot_speed) - txt->ray->plane_y * sin(rot_speed);
	txt->ray->plane_y = oldplane_x * sin(rot_speed) + txt->ray->plane_y * cos(rot_speed);
	txt->mv = 1;
}

int	act_move(t_txt *txt)
{
	if (txt->forw == 1)
		mv_forw(txt);
	if (txt->back == 1)
		mv_back(txt);
	if (txt->left == 1)
		mv_left(txt);
	if (txt->right == 1)
		mv_right(txt);
	if (txt->cleft == 1)
		rot_cam(txt, RS);
	if (txt->cright == 1)
		rot_cam(txt, -RS);
	if (txt->mv == 1)
		setup_ray(txt);
	return (0);
}