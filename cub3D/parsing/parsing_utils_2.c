/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:39:49 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/15 17:23:41 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	direction_2(t_txt *txt, char c)
{
	if (c == 'E')
	{
		txt->ray->dir_x = 0;
		txt->ray->dir_y = 1;
		txt->ray->plane_x = 0.66;
		txt->ray->plane_y = 0;
	}
	if (c == 'W')
	{
		txt->ray->dir_x = 0;
		txt->ray->dir_y = -1;
		txt->ray->plane_x = -0.66;
		txt->ray->plane_y = 0;
	}
}

void	direction(t_txt *txt, char c, int y, int x)
{
	if (c == 'N')
	{
		txt->ray->dir_x = -1;
		txt->ray->dir_y = 0;
		txt->ray->plane_x = 0;
		txt->ray->plane_y = 0.66;
	}
	if (c == 'S')
	{
		txt->ray->dir_x = 1;
		txt->ray->dir_y = 0;
		txt->ray->plane_x = 0;
		txt->ray->plane_y = -0.66;
	}
	txt->ray->pos_x = x;
	txt->ray->pos_y = y;
	direction_2(txt, c);
}


int	check_nb(t_txt *txt)
{
	if (txt->txt[0] && txt->txt[1] && txt->txt[2]
		&& txt->txt[3] && txt->txt[4] && txt->txt[5])
		return (1);
	return (0);
}

int	map_line_v(char *s, t_txt *txt)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '\n' && s[i] != ' ' && s[i] != '1' && s[i] != '0' && s[i] != 'N'
			&& s[i] != 'E' && s[i] != 'W' && s[i] != 'S')
			error_dir(s, txt, 3);
		i++;
	}
	return (1);
}