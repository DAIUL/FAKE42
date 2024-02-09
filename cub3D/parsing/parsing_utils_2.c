/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:39:49 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/09 17:42:00 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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