/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:01:54 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/09 00:48:56 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_map(char **s, t_txt *txt)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i])
			free(s[i]);
		i++;
	}
	free(s);
	i = 0;
	while (i < 6)
	{
		if (txt->txt[i])
			free(txt->txt[i]);
		i++;
	}
	free(txt->txt);
	free(txt);
	ft_printf("Map ouverte\n");
	exit(EXIT_FAILURE);
}

void	error_dir(char *s, t_txt *txt)
{
	int	i;

	free(s);
	i = 0;
	while (i < 6)
	{
		if (txt->txt[i])
			free(txt->txt[i]);
		i++;
	}
	free(txt->txt);
	free(txt);
	ft_printf("Manque de texture avant generation de la map\n");
	exit(EXIT_FAILURE);
}

void	error_fd(t_txt *txt)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (txt->txt[i])
			free(txt->txt[i]);
		i++;
	}
	free(txt->txt);
	free(txt);
	ft_printf("Erreur de fichier\n");
	exit(EXIT_FAILURE);
}