/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:58:47 by qpuig             #+#    #+#             */
/*   Updated: 2024/01/27 16:58:47 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	len_txt(int i, char *s)
{
	int	j;

	j = 0;
	while (s[i] && (s[i] != '\n' && s[i] != ' ' && s[i] != '\t'))
	{
		j++;
		i++;
	}
	return (j);
}

void	fill_txt(char *s, int id, t_txt *txt)
{
	int	i;

	i = 2;
	if (txt->txt[id])
		error_dir(s, txt, 1);
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] && s[i] != '\n')
		txt->txt[id] = ft_strndup(s, i, len_txt(i, s));
}

int	skip_till_elem(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	end_map(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == '\n')
		return (2);
	return (0);
}