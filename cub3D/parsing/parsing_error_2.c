/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:26:29 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/19 23:17:48 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	ft_free_img(t_txt *txt)
{
	int	i;

	i = 0;
	while (txt->img[i].ptr)
	{
		mlx_destroy_image(txt->mlx_ptr, txt->img[i].ptr);
		i++;
	}
	free(txt->img);
}

void	free_map(t_txt *txt)
{
	int	i;

	i = 0;
	while (txt->fmap[i])
	{
		if (txt->fmap[i])
			free(txt->fmap[i]);
		i++;
	}
	free(txt->fmap);
}