/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:57:44 by qpuig             #+#    #+#             */
/*   Updated: 2023/05/26 19:50:02 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_rectangle(char **map)
{
	int	len;
	int	y;

	y = 0;
	while (map[y][0])
		y++;
	y--;
	len = y;
	while (len >= 0)
	{
		if (ft_strlen(map[y]) == ft_strlen(map[len]))
			len--;
		else
			ft_failure("That's not a rectangle u dumb bitch");
	}
	return;
}

void	ft_check_wall(char **map)
{
	int	x;
	int	y;
	int	lenx;
	int	leny;

	leny = 0;
	while (map[leny][0])
		leny++;
	lenx = 0;
	while (map[0][lenx])
		lenx++;
	x = 0;
	while ((map[leny - 1][x] == '1') && (map[0][x] == '1'))
		x++;
	if (x != lenx)
		ft_failure("Missing wall u bastard");
	y = 0;
	while ((map[y][0]) && (map[y][lenx - 1] == '1') && (map[y][0] == '1'))
	{
		ft_printf("%d\n", y);
		y++;
	}
	if (y != leny)
		ft_failure("Missing wall u bastard");
	return;
}

int	ft_check_epc(char **map)
{
	int			x;
	int			y;
	static int	e = 0;
	static int	p = 0;
	static int	c = 0;

	y = -1;
	while (map[++y][0])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'E')
				e++;
			if (map[y][x] == 'P')
				p++;
			if (map[y][x] == 'C')
				c++;
		}
	}
	ft_printf("%i", e + p + c);
	if (e != 1 || p != 1 || c < 1)
		ft_failure("Missing special item loser");
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
	ft_printf("%d\n", collect);
	return (verif);
}
