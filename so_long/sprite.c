/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:38:29 by qpuig             #+#    #+#             */
/*   Updated: 2023/08/09 20:42:20 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_failure(t_mlx *mlx, char *message)
{
	ft_printf("%s\n", message);
	ft_freesl(mlx);
	exit(EXIT_FAILURE);
}

t_sprt	ft_create(void *mlx_ptr, char *path)
{
	t_sprt	sprt;

	sprt.pointer = mlx_xpm_file_to_image(mlx_ptr, path, &sprt.x, &sprt.y);
	sprt.pixels = mlx_get_data_addr(sprt.pointer, &sprt.bits_per_pixel,
			&sprt.line_size, &sprt.endian);
	return (sprt);
}

t_sprt	*ft_stock(void *mlx_ptr)
{
	t_sprt	*sprt;

	sprt = ft_calloc(14, sizeof(t_sprt));
	sprt[0] = ft_create(mlx_ptr, "./sprites/sprite0.xpm");
	sprt[1] = ft_create(mlx_ptr, "./sprites/sprite01.xpm");
	sprt[2] = ft_create(mlx_ptr, "./sprites/sprite02.xpm");
	sprt[3] = ft_create(mlx_ptr, "./sprites/sprite03.xpm");
	sprt[4] = ft_create(mlx_ptr, "./sprites/sprite1.xpm");
	sprt[5] = ft_create(mlx_ptr, "./sprites/sprite2.xpm");
	sprt[6] = ft_create(mlx_ptr, "./sprites/sprite3.xpm");
	sprt[7] = ft_create(mlx_ptr, "./sprites/sprite4.xpm");
	sprt[8] = ft_create(mlx_ptr, "./sprites/sprite5.xpm");
	sprt[9] = ft_create(mlx_ptr, "./sprites/sprite60.xpm");
	sprt[10] = ft_create(mlx_ptr, "./sprites/sprite61.xpm");
	sprt[11] = ft_create(mlx_ptr, "./sprites/sprite62.xpm");
	sprt[12] = ft_create(mlx_ptr, "./sprites/sprite63.xpm");
	return (sprt);
}
