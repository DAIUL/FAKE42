/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:04:26 by qpuig             #+#    #+#             */
/*   Updated: 2023/08/08 20:18:39 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_croix(t_mlx *mlx)
{
	ft_freesl(mlx);
	exit(EXIT_FAILURE);
	return (0);
}

	void	ft_freeslmap(t_mlx *mlx)
{
	int	y;

	y = 0;
	while (mlx->map[y][0])
	{
		free(mlx->map[y]);
		y++;
	}
	free(mlx->map[y]);
	free(mlx->map);
}

void	ft_freesl(t_mlx *mlx)
{
	int	i;

	i = 0;
	ft_freeslmap(mlx);
	free(mlx->nbrats);
	if (mlx->sprites)
	{
		while (mlx->sprites[i].pointer)
		{
			mlx_destroy_image(mlx->mlx_ptr, mlx->sprites[i].pointer);
			i++;
		}
	}
	free(mlx->sprites);
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	srand(time(NULL));
	mlx.mlx_ptr = mlx_init();
	mlx.map = ft_map(argc, argv);
	ft_check_rectangle(&mlx);
	ft_check_wall(&mlx);
	mlx.window = mlx_new_window(mlx.mlx_ptr, (mlx.lenx * 64), (mlx.leny * 64 + 30), "Philippe EtcheQuest");
	mlx_set_font(mlx.mlx_ptr, mlx.window, "-misc-fixed-bold-r-normal--20-0-100-100-c-0-iso10646-1");
	if (ft_check_winable(mlx.map, ft_pos(mlx.map).y, ft_pos(mlx.map).x, ft_check_epc(&mlx)) == 0)
		ft_failure(&mlx, "That's not finished stupid bitch");
	mlx.tcollect = (ft_check_epc(&mlx) - 2);
	mlx.sprites = NULL;
	mlx.stop = 0;
	mlx.step = 0;
	ft_freeslmap(&mlx);
	mlx.map = ft_map(argc, argv);
	ft_nbrats(&mlx);
	mlx.sprites = ft_stock(mlx.mlx_ptr);
	ft_display(mlx.map, mlx);
	mlx_key_hook(mlx.window, &jab_jab_hook, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &ft_anim, &mlx);
	mlx_hook(mlx.window, 17, 0, &ft_croix, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
