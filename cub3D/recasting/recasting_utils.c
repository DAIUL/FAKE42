/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:39:04 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/18 22:26:26 by qpuig            ###   ########.fr       */
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
	if (txt->ray->side == 0)
		txt->ray->wallX = txt->ray->posY + txt->ray->perpWallDist
			* txt->ray->raydirY;
	else
		txt->ray->wallX = txt->ray->posX + txt->ray->perpWallDist
			* txt->ray->raydirX;
	txt->ray->wallX -= floor(txt->ray->wallX);
	txt->ray->texNum = index_texture(g);
	txt->ray->texX = (int)(txt->ray->wallX * TEXWIDTH);
	if (txt->ray->side == 0 && txt->ray->raydirX < 0)
		txt->ray->texX = TEXWIDTH - txt->ray->texX - 1;
	if (txt->ray->side == 1 && txt->ray->raydirY > 0)
		txt->ray->texX = TEXWIDTH - txt->ray->texX - 1;
}

void	setup_texture(t_txt *txt, int x)
{
	int	y;

	y = txt->ray->drawStart;
	txt->ray->step = 1.0 * TEXHEIGHT / txt->ray->lineHeight;
	txt->ray->texPos = (txt->ray->drawStart - SCREENHEIGHT / 2
			+ txt->ray->lineHeight / 2) * txt->ray->step;
	while (y < txt->ray->drawEnd)
	{
		txt->ray->texY = (int)txt->ray->texPos & (TEXHEIGHT - 1);
		txt->ray->texPos += txt->ray->step;
		txt->ray->color = txt->img[txt->ray->texNum].addr[TEXHEIGHT
			* txt->ray->texY + txt->ray->texX];
		if (txt->ray->color > 0)
			txt->buffer[y][x] = txt->ray->color;
		y++;
	}
	txt->ray->z_buffer[x] = txt->ray->perpWallDist;
}