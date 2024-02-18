/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:26:06 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/18 16:59:14 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

if(keyDown(SDLK_UP))
    {
      if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if(keyDown(SDLK_DOWN))
    {
      if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    }
    //rotate to the right
    if(keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if(keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);

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
	else if (keycode == W || keycode == UP)
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