/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:12:59 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/20 11:58:58 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_close(t_txt *txt)
{
	free_all(txt);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	render_frame(t_txt *txt)
{
	int		x;
	int		y;
	int		pixel;

	y = 0;
	while (y < SCREENHEIGHT)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			pixel = y * (txt->render->length / 4) + x;
			if (txt->buffer[y][x] > 0)
				txt->render->addr[pixel] = txt->buffer[y][x];
			else if (y < SCREENHEIGHT / 2)
				txt->render->addr[pixel] = txt->hex[1];
			else if (y < SCREENHEIGHT -1)
				txt->render->addr[pixel] = txt->hex[0];
			x++;
		}
		y++;
	}
}

static void	prepare_render(t_txt *txt)
{
	int	y;

	y = 0;
	if (txt->render)
	{
		mlx_destroy_image(txt->mlx_ptr, txt->render->ptr);
		free(txt->render);
	}
	txt->render = ft_calloc(sizeof(t_img), 1);
	txt->render->ptr = mlx_new_image(txt->mlx_ptr, SCREENWIDTH, SCREENHEIGHT);
	txt->render->addr = (int *)mlx_get_data_addr(txt->render->ptr,
			&txt->render->bpp,
			&txt->render->length, &txt->render->endian);
	ft_free_buffer(txt);
	txt->buffer = ft_calloc(sizeof * txt->buffer, SCREENHEIGHT + 1);
	while (y < SCREENHEIGHT)
	{
		txt->buffer[y] = ft_calloc(sizeof * txt->buffer, SCREENWIDTH + 1);
		y++;
	}
}

void	setup_ray(t_txt *txt)
{
	int	x;

	txt->ray->time = 0;
	txt->ray->old_time = 0;
	prepare_render(txt);
	x = 0;
	while (x < SCREENWIDTH)
	{
		raycasting(txt, x);
		setup_sidedist(txt);
		setup_hit(txt);
		setup_draw(txt);
		setup_texture(txt, x);
		x++;
	}
	render_frame(txt);
	mlx_put_image_to_window(txt->mlx_ptr, txt->window, txt->render->ptr, 0, 0);
}

void	main_draw(t_txt *txt)
{
	txt->mlx_ptr = mlx_init();
	txt->window = mlx_new_window(txt->mlx_ptr,
			SCREENWIDTH, SCREENHEIGHT, "cub3d");
	if (!add_texture(txt))
		return ;
	txt->ray->z_buffer = ft_calloc(sizeof(double), SCREENWIDTH + 1);
	setup_ray(txt);
	mlx_hook(txt->window, 2, (1L << 0), &press_key, txt);
	mlx_hook(txt->window, 3, (1L << 1), &release_key, txt);
	mlx_hook(txt->window, 17, 0, &ft_close, txt);
	mlx_loop_hook(txt->mlx_ptr, &act_move, txt);
	mlx_loop(txt->mlx_ptr);
	ft_close(txt);
}
