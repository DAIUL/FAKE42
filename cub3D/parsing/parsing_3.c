/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:34:15 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/09 00:34:15 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

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
				break;
			if ((s[i][j] != '1' && s[i][j] != ' ') && !s[i + 1])
				error_map(s, txt);
			if (s[i + 1] && ((unsigned int)j > ft_strlen(s[i + 1])) && (s[i][j] != '1' && s[i][j] != ' '))
				error_map(s, txt);
			if (s[i][j] == ' ' && (s[i + 1][j] != ' ' && s[i + 1][j] != '1'
				&& s[i + 1][j] != '\0'))
				error_map(s, txt);
			if ((s[i][j] == 'N' || s[i][j] == 'E' || s[i][j] == 'W' || s[i][j] == 'S')
				&& (s[i + 1][j] != '0' && s[i + 1][j] != '1'))
				error_map(s, txt);
 			if (s[i][j] == '0'	
				&& (s[i + 1][j] != 'N' && s[i + 1][j] != 'E' && s[i + 1][j] != 'W'
				&& s[i + 1][j] != 'S' && s[i + 1][j] != '1' && s[i + 1][j] != '0'))
				error_map(s, txt);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}