/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:01:54 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/12 17:41:07 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_map(char **s, t_txt *txt, int mes)
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
	if (mes == 1)
		ft_printf("Map ouverte\n");
	if (mes == 2)
		ft_printf("Mauvaise quantite de position de depart\n");
	exit(EXIT_FAILURE);
}

void	error_dir(char *s, t_txt *txt, int mes)
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
	if (mes == 1)
		ft_printf("Texture en double\n");
	if (mes == 2)
		ft_printf("Manque de texture avant generation de la map\n");
	if (mes == 3)
		ft_printf("Caractere inconnu\n");
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