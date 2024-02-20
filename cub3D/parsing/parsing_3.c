/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:34:15 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/20 11:15:28 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_dir_line(char *s, t_txt *txt)
{
	int	i;

	if ((ft_strncmp(s, "NO ", 3) == 0))
		fill_txt(s, NO, txt);
	else if (ft_strncmp(s, "SO ", 3) == 0)
		fill_txt(s, SO, txt);
	else if (ft_strncmp(s, "EA ", 3) == 0)
		fill_txt(s, EA, txt);
	else if (ft_strncmp(s, "WE ", 3) == 0)
		fill_txt(s, WE, txt);
	else if (ft_strncmp(s, "C ", 2) == 0)
		fill_txt(s, C, txt);
	else if (ft_strncmp(s, "F ", 2) == 0)
		fill_txt(s, F, txt);
	else
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '1' || s[i] == '0' || s[i] == 'N'
				|| s[i] == 'E' || s[i] == 'W' || s[i++] == 'S')
				return (0);
		}
	}
	return (1);
}

void	check_map_line_2(char **s, t_txt *txt, int i, int j)
{
	if (s[i][j] == ' ' && (s[i][j + 1] != ' ' && s[i][j + 1] != '1'
		&& s[i][j + 1] != '\0'))
		error_map(txt, 1);
	if ((s[i][j] == 'N' || s[i][j] == 'E' || s[i][j] == 'W' || s[i][j] == 'S')
		&& (s[i][j + 1] != '0' && s[i][j + 1] != '1'))
		error_map(txt, 1);
	if (s[i][j] == '0'
		&& (s[i][j + 1] != 'N' && s[i][j + 1] != 'E' && s[i][j + 1] != 'W'
		&& s[i][j + 1] != 'S' && s[i][j + 1] != '1' && s[i][j + 1] != '0'))
		error_map(txt, 1);
}

int	check_map_line(char **s, t_txt *txt)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if ((s[i][j] == 'N' || s[i][j] == 'E'
				|| s[i][j] == 'W' || s[i][j] == 'S')
				&& (s[i][j + 1] == '0' || s[i][j + 1] == '1'))
			{
				txt->start += 1;
				direction(txt, s[i][j], i, j);
			}
			check_map_line_2(s, txt, i, j);
			j++;
		}
		if (txt->start > 1)
			error_map(txt, 2);
		i++;
	}
	return (1);
}

void	check_line_vert_2(char **s, t_txt *txt, int i, int j)
{
	if ((s[i][j] != '1' && s[i][j] != ' ') && !s[i + 1])
		error_map(txt, 1);
	if (s[i + 1] && ((unsigned int)j > ft_strlen(s[i + 1]))
		&& (s[i][j] != '1' && s[i][j] != ' '))
		error_map(txt, 1);
	if (s[i][j] == ' ' && (s[i + 1][j] != ' ' && s[i + 1][j] != '1'
		&& s[i + 1][j] != '\0'))
		error_map(txt, 1);
	if ((s[i][j] == 'N' || s[i][j] == 'E' || s[i][j] == 'W' || s[i][j] == 'S')
		&& (s[i + 1][j] != '0' && s[i + 1][j] != '1'))
		error_map(txt, 1);
	if (s[i][j] == '0'
		&& (s[i + 1][j] != 'N' && s[i + 1][j] != 'E' && s[i + 1][j] != 'W'
		&& s[i + 1][j] != 'S' && s[i + 1][j] != '1' && s[i + 1][j] != '0'))
		error_map(txt, 1);
}

int	check_line_vert(char **s, t_txt *txt)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i][j])
	{
		while (s[i] && s[i][j])
		{
			if ((s[i][j] == '1' || s[i][j] == ' ') && !s[i + 1])
				break ;
			check_line_vert_2(s, txt, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
