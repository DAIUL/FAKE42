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

int	main(void)
{
	t_mlx	mlx;
	mlx.mlx_ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "Philippe EtcheQuest");
	mlx.map = ft_map();
	ft_view(mlx.map);
	ft_check_rectangle(mlx.map);
	ft_check_wall(mlx.map);
	if (ft_check_winable(mlx.map, ft_pos(mlx.map).y, ft_pos(mlx.map).x, ft_check_epc(mlx.map)) == 0)
		ft_failure("That's not finished stupid bitch");
	mlx.tcollect = (ft_check_epc(mlx.map) - 2);
	mlx.stop = 0;
	ft_view(mlx.map);
	free(mlx.map);
	mlx.map = ft_map();
	ft_view(mlx.map);
	mlx.sprites = ft_stock(mlx.mlx_ptr);
	ft_display(mlx.map, mlx);
	mlx_key_hook(mlx.window, &jab_jab_hook, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &ft_anim, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
