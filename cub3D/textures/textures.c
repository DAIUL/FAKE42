/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:04:48 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/18 22:47:15 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	ft_add_img(t_txt *txt, char *path)
{
	t_img	img;

	if (!path[0])
	{
		img.ptr = NULL;
		img.addr = NULL;
		img.x = 0;
		img.y = 0;
		img.bpp = 0;
		img.length = 0;
		img.endian = 0;
	}
	else
	{
		img.ptr = mlx_xpm_file_to_image(txt->mlx,
				path, &img.x, &img.y);
		img.addr = (int *)mlx_get_data_addr(img.ptr, &img.bpp,
				&img.length, &img.endian);
	}
	return (img);
}

int	add_texture(t_txt *txt)
{
	t_img	*img;

	img = ft_calloc(5, sizeof(t_img));
	img[0] = ft_add_img(txt, txt->tex[0]);
	img[1] = ft_add_img(txt, txt->tex[1]);
	img[2] = ft_add_img(txt, txt->tex[2]);
	img[3] = ft_add_img(txt, txt->tex[3]);
	img[4] = ft_add_img(txt, "");
	txt->img = img;
	return (1);
}