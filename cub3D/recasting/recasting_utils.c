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
	txt->ray->camera_x = 2 * x / (double)screenWidth - 1;
	txt->ray->ray_dir_x = txt->ray->dirX + txt->ray->plane_x * txt->ray->camera_x;
	txt->ray->ray_dir_y = txt->ray->dirY + txt->ray->plane_y * txt->ray->camera_x;
	txt->ray->map_x = (int)txt->ray->pos_X;
	txt->ray->map_x = (int)txt->ray->pos_X;
	txt->ray->delta_dist_x = fabs(1 / txt->ray->ray_dir_x);
	txt->ray->delta_dist_y = fabs(1 / txt->ray->ray_dir_y);
	txt->ray->hit = 0;
}

void	setup_sidedist(t_txt *txt)
{
	if(txt->ray->ray_dir_x < 0)
    {
        txt->ray->step_x = -1;
        txt->ray->side_dist_x = (txt->ray->pos_X - txt->ray->map_x) * txt->ray->delta_dist_x;
    }
    else
    {
        txt->ray->step_x = 1;
        txt->ray->side_dist_x = (txt->ray->map_x + 1.0 - txt->ray->pos_X) * txt->ray->delta_dist_x;
    }
    if(txt->ray->ray_dir_y < 0)
    {
        txt->ray->step_y = -1;
        txt->ray->side_dist_y = (txt->ray->pos_y - txt->ray->map_y) * txt->ray->delta_dist_y;
    }
    else
    {
        txt->ray->step_y = 1;
		txt->ray->side_dist_y = (txt->ray->map_y + 1.0 - txt->ray->pos_y) * txt->ray->delta_dist_y;
	}
}

void	setup_hit(t_txt *txt)
{
	while(txt->ray->hit == 0)
    {
	    if(txt->ray->side_dist_x < txt->ray->side_dist_y)
    	{
        	txt->ray->side_dist_x += txt->ray->delta_dist_x;
    		txt->ray->map_x += txt->ray->step_x;
        	txt->ray->side = 0;
        }
        else
        {
        	txt->ray->side_dist_y += txt->ray->delta_dist_y;
        	txt->ray->map_y += txt->ray->step_y;
        	txt->ray->side = 1;
        }
        if(txt->fmap[map_x][map_y] > 0)
			txt->ray->hit = 1;
    }
	if(txt->ray->side == 0)
		txt->ray->perp_wall_dist = (txt->ray->side_dist_x - txt->ray->delta_dist_x);
    else
		txt->ray->perp_wall_dist = (txt->ray->side_dist_y - txt->ray->delta_dist_y);
}

void	setup_draw(t_txt *txt)
{
	txt->ray->line_height = (int)(screenHeight / txt->ray->perp_wall_dist);
	txt->ray->draw_start = -txt->ray->line_height / 2 + screenHeight / 2;
    if (txt->ray->draw_start < 0)
		txt->ray->draw_start = 0;
    txt->ray->draw_end = txt->ray->line_height / 2 + screenHeight / 2;
    if(txt->ray->draw_end >= screenHeight)
		txt->ray->draw_end = screenHeight - 1;
	if (txt->ray->side == 0)
		txt->ray->wall_x = txt->ray->pos_y + txt->ray->perp_wall_dist
			* txt->ray->ray_dir_y;
	else
		txt->ray->wall_x = txt->ray->pos_X + txt->ray->perp_wall_dist
			* txt->ray->ray_dir_x;
	txt->ray->wall_x -= floor(txt->ray->wall_x);
	txt->ray->tex_num = index_texture(g);
	txt->ray->tex_x = (int)(txt->ray->wall_x * TEXWIDTH);
	if (txt->ray->side == 0 && txt->ray->ray_dir_x < 0)
		txt->ray->tex_x = TEXWIDTH - txt->ray->tex_x - 1;
	if (txt->ray->side == 1 && txt->ray->ray_dir_y > 0)
		txt->ray->tex_x = TEXWIDTH - txt->ray->tex_x - 1;
}

void	setup_texture(t_txt *txt, int x)
{
	int	y;

	y = txt->ray->draw_start;
	txt->ray->step = 1.0 * TEXHEIGHT / txt->ray->line_height;
	txt->ray->tex_pos = (txt->ray->draw_start - SCREENHEIGHT / 2
			+ txt->ray->line_height / 2) * txt->ray->step;
	while (y < txt->ray->draw_end)
	{
		txt->ray->tex_y = (int)txt->ray->tex_pos & (TEXHEIGHT - 1);
		txt->ray->tex_pos += txt->ray->step;
		txt->ray->color = txt->img[txt->ray->tex_num].addr[TEXHEIGHT
			* txt->ray->tex_y + txt->ray->tex_x];
		if (txt->ray->color > 0)
			txt->buffer[y][x] = txt->ray->color;
		y++;
	}
	txt->ray->z_buffer[x] = txt->ray->perp_wall_dist;
}