/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:12:59 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/12 19:05:55 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	main_draw(t_txt *txt)
{
	txt->mlx_ptr = mlx_init();
	txt->window = mlx_new_window(txt->mlx_ptr, 1920, 1080, "cub3d");
	mlx_loop(txt->mlx_ptr);
}