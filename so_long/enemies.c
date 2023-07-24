/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:52 by qpuig             #+#    #+#             */
/*   Updated: 2023/07/07 18:04:10 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	ft_posr(char **map, int yr, int xr)
{
	t_pos	pos;
	int	y;
	int	x;

	y = yr;
    x = xr;
	while (map[y][0])
	{
        if (y != yr)
		    x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'R')
			{
				pos.yr = y;
				pos.xr = x;
                return (pos);
			}
			x++;
		}
		y++;
	}
    pos.xr = -1;
	return (pos);
}

void    ft_enemiesmvmt(t_mlx *mlx, t_pos pos, int yr, int xr)
{   
    if (mlx->map[pos.yr + yr][pos.xr + xr] == '1' || mlx->map[pos.yr + yr][pos.xr + xr] == 'C' || mlx->map[pos.yr + yr][pos.xr + xr] == 'E') 
		return;
    mlx->map[pos.yr][pos.xr] = '0';
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->sprites[5].pointer, (pos.xr * 64), (pos.yr * 64));
	pos.xr += xr;
	pos.yr += yr;
	mlx->map[pos.yr][pos.xr] = 'R';
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->sprites[9].pointer, (pos.xr * 64), (pos.yr * 64));
}

void    ft_enemies(t_mlx *mlx)
{
    t_pos   pos;
    int r;

    pos = ft_posr(mlx->map, 0, 0);
    srand(time(NULL));
    while (pos.xr != -1)
    {
        r = rand() % 5;
        if (r == 0)
            ft_enemiesmvmt(mlx, pos, 0, 0);
        if (r == 1)
            ft_enemiesmvmt(mlx, pos, 0, -1);
        if (r == 2)
            ft_enemiesmvmt(mlx, pos, 1, 0);
        if (r == 3)
            ft_enemiesmvmt(mlx, pos, 0, 1);
        if (r == 4)
            ft_enemiesmvmt(mlx, pos, -1, 0);
        pos = ft_posr(mlx->map, pos.yr, pos.xr + 1);
        ft_printf("%i\n", r);
    }
}

void    ft_animr(t_mlx *mlx, int r)
{
    t_pos   pos;

    pos = ft_posr(mlx->map, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->sprites[r].pointer, (pos.xr * 64), (pos.yr * 64));
}