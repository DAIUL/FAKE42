/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:39:04 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/16 17:40:27 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d"

void	raycasting(t_txt *txt)
{
	txt->ray->cameraX = 2 * x / (double)screenWidth - 1;
	txt->ray->rayDirX = txt->ray->dirX + txt->ray->planeX * txt->ray->cameraX;
	txt->ray->rayDirY = txt->ray->dirY + txt->ray->planeY * txt->ray->cameraX;
	txt->ray->mapX = (int)txt->ray->posX;
	txt->ray->mapX = (int)txt->ray->posX;
	txt->ray->deltaDistX = fabs(1 / txt->ray->rayDirX);
	txt->ray->deltaDistY = fabs(1 / txt->ray->rayDirY);
	txt->ray->hit = 0;
}

void	setup_sidedist(t_txt *txt)
{
	if(txt->ray->rayDirX < 0)
    {
        txt->ray->stepX = -1;
        txt->ray->sideDistX = (txt->ray->posX - txt->ray->mapX) * txt->ray->deltaDistX;
    }
    else
    {
        txt->ray->stepX = 1;
        txt->ray->sideDistX = (txt->ray->mapX + 1.0 - txt->ray->posX) * txt->ray->deltaDistX;
    }
    if(txt->ray->rayDirY < 0)
    {
        txt->ray->stepY = -1;
        txt->ray->sideDistY = (txt->ray->posY - txt->ray->mapY) * txt->ray->deltaDistY;
    }
    else
    {
        txt->ray->stepY = 1;
		txt->ray->sideDistY = (txt->ray->mapY + 1.0 - txt->ray->posY) * txt->ray->deltaDistY;
	}
}

void	setup_hit(t_txt *txt)
{
	while(txt->ray->hit == 0)
    {
	    if(txt->ray->sideDistX < txt->ray->sideDistY)
    	{
        	txt->ray->sideDistX += txt->ray->deltaDistX;
    		txt->ray->mapX += txt->ray->stepX;
        	txt->ray->side = 0;
        }
        else
        {
        	txt->ray->sideDistY += txt->ray->deltaDistY;
        	txt->ray->mapY += txt->ray->stepY;
        	txt->ray->side = 1;
        }
        if(txt->fmap[mapX][mapY] > 0)
			txt->ray->hit = 1;
    }
	if(txt->ray->side == 0)
		txt->ray->perpWallDist = (txt->ray->sideDistX - txt->ray->deltaDistX);
    else
		txt->ray->perpWallDist = (txt->ray->sideDistY - txt->ray->deltaDistY);
}

void	setup_draw(t_txt *txt)
{
	txt->ray->lineHeight = (int)(screenHeight / txt->ray->perpWallDist);
	txt->ray->drawStart = -txt->ray->lineHeight / 2 + screenHeight / 2;
    if (txt->ray->drawStart < 0)
		txt->ray->drawStart = 0;
    txt->ray->drawEnd = txt->ray->lineHeight / 2 + screenHeight / 2;
    if(txt->ray->drawEnd >= screenHeight)
		txt->ray->drawEnd = screenHeight - 1;
}