/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:04:26 by qpuig             #+#    #+#             */
/*   Updated: 2023/05/26 19:43:22 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freesl(t_mlx *mlx)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (mlx->map[y][0])
	{
		free(mlx->map[y]);
		y++;
	}
	free(mlx->map[y]);
	free(mlx->map);
	if (mlx->sprites)
	{
		while (mlx->sprites[i].pointer)
		{
			mlx_destroy_image(mlx->mlx_ptr, mlx->sprites);
			i++;
		}
	}
	ft_printf("freeze corleone\n");
}

void	ft_view(char **map)
{
	int	y;

	y = 0;
	while (map[y][0])
	{
		ft_printf("%s\n", map[y]);
		y++;
	}
	return;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	srand(time(NULL));
	mlx.mlx_ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "Philippe EtcheQuest");
	mlx.map = ft_map(argc, argv);
	ft_view(mlx.map);
	ft_check_rectangle(&mlx);
	ft_check_wall(&mlx);
	if (ft_check_winable(mlx.map, ft_pos(mlx.map).y, ft_pos(mlx.map).x, ft_check_epc(&mlx)) == 0)
		ft_failure(&mlx, "That's not finished stupid bitch");
	mlx.tcollect = (ft_check_epc(&mlx) - 2);
	mlx.sprites = NULL;
	mlx.stop = 0;
	ft_view(mlx.map);
	ft_freesl(&mlx);
	mlx.map = ft_map(argc, argv);
	ft_view(mlx.map);
	ft_nbrats(&mlx);
	mlx.sprites = ft_stock(mlx.mlx_ptr);
	ft_display(mlx.map, mlx);
	mlx_key_hook(mlx.window, &jab_jab_hook, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &ft_anim, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
