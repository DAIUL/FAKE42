/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:57:44 by qpuig             #+#    #+#             */
/*   Updated: 2023/08/08 20:01:46 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_rectangle(t_mlx *mlx)
{
	int	len;
	int	y;

	y = 0;
	while (mlx->map[y][0])
		y++;
	mlx->leny = y;
	y--;
	len = y;
	while (len >= 0)
	{
		if (ft_strlen(mlx->map[y]) == ft_strlen(mlx->map[len]))
			len--;
		else
			ft_failure(mlx, "That's not a rectangle u dumb bitch");
	}
	return;
}

void	ft_check_wall(t_mlx *mlx)
{
	int	x;
	int	y;
	int	lenx;
	int	leny;

	leny = 0;
	while (mlx->map[leny][0])
		leny++;
	lenx = 0;
	while (mlx->map[0][lenx])
		lenx++;
	mlx->lenx = lenx;
	x = 0;
	while ((mlx->map[leny - 1][x] == '1') && (mlx->map[0][x] == '1'))
		x++;
	if (x != lenx)
		ft_failure(mlx, "Missing wall u bastard");
	y = 0;
	while ((mlx->map[y][0]) && (mlx->map[y][lenx - 1] == '1') && (mlx->map[y][0] == '1'))
		y++;
	if (y != leny)
		ft_failure(mlx, "Missing wall u bastard");
	return;
}

int	ft_check_epc(t_mlx *mlx)
{
	int			x;
	int			y;
	static int	e = 0;
	static int	p = 0;
	static int	c = 0;

	y = -1;
	while (mlx->map[++y][0])
	{
		x = -1;
		while (mlx->map[y][++x])
		{
			if (mlx->map[y][x] == 'E')
				e++;
			if (mlx->map[y][x] == 'P')
				p++;
			if (mlx->map[y][x] == 'C')
				c++;
		}
	}
	if (e != 1 || p != 1 || c < 1)
		ft_failure(mlx, "Missing or too much special item loser");
	return (e + p + c);
}

t_pos	ft_pos(char **map)
{
	t_pos	pos;
	int	y;
	int	x;

	y = 0;
	pos.y = 0;
	pos.x = 0;
	while (map[y][0])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos.y = y;
				pos.x = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

int	ft_check_winable(char **map, int y, int x, int epc)
{
	static int	collect = 0;
	static int	verif = 0;

	if (map[y][x] == '1' || map[y][x] == 'V')
		return (verif);
	if (map[y][x] == 'E' || map[y][x] == 'C' || map[y][x] == 'P')
		collect++;
	if (collect == epc)
		verif = 1;
	map[y][x] = 'V';
	ft_check_winable(map, (y - 1), x, epc);
	ft_check_winable(map, y, (x + 1), epc);
	ft_check_winable(map, (y + 1), x, epc);
	ft_check_winable(map, y, (x - 1), epc);
	return (verif);
}
