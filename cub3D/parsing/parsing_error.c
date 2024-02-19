/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:01:54 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/19 23:20:45 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all_2(t_txt *txt)
{
	if (txt->render)
	{
		mlx_destroy_image(txt->mlx_ptr, txt->render->ptr);
		free(txt->render);
	}
	if (txt->ray)
		free(txt->ray);
	if (txt->mlx_ptr)
	{
		mlx_destroy_window(txt->mlx_ptr, txt->window);
		mlx_destroy_display(txt->mlx_ptr);
		free(txt->mlx_ptr);
	}
}

void	free_all(t_txt *txt)
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
	if (txt->fmap)
		free_map(txt);
	if (txt->img)
		ft_free_img(txt);
	if (txt->ray && txt->ray->z_buffer)
		free(txt->ray->z_buffer);
	free_all_2(txt);
	ft_free_buffer(txt);
	free(txt);
}

void	error_map(t_txt *txt, int mes)
{
	int	i;

	free_map(txt);
	i = 0;
	while (i < 6)
	{
		if (txt->txt[i])
			free(txt->txt[i]);
		i++;
	}
	free(txt->txt);
	free(txt->ray);
	free(txt);
	if (mes == 1)
		ft_printf("Map ouverte\n");
	if (mes == 2)
		ft_printf("Mauvaise quantite de position de depart\n");
	if (mes == 3)
		ft_printf("Textures invalides\n");
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
	free(txt->ray);
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
	free(txt->ray);
	free(txt);
	ft_printf("Erreur de fichier\n");
	exit(EXIT_FAILURE);
}