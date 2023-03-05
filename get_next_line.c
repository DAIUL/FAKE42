/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:12:18 by qpuig             #+#    #+#             */
/*   Updated: 2023/03/05 20:50:03 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_return(char *rest)
{
	char	*truc;
	int		i;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	truc = malloc((i + 2) * sizeof(char));
	if (!truc)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		truc[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		truc[i] = rest[i];
		i++;
	}
	truc[i] = '\0';
	return (truc);
}

char	*ft_restjoin(int fd, char *rest)
{
	char	*bufs;
	int		lect;

	bufs = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!bufs)
		return (NULL);
	lect = 1;
	while (lect != 0 && ft_check(rest, '\n') == 0)
	{
		lect = read(fd, bufs, BUFFER_SIZE);
		if (lect <= 0)
		{
			free(bufs);
			return (NULL);
		}
		bufs[lect] = '\0';
		rest = ft_strjoin(rest, bufs);
	}
	free (bufs);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*truc;
	static char	*rest;

	truc = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_restjoin(fd, rest);
	if (!rest)
		return (NULL);
	truc = ft_return(rest);
	rest = ft_rest(rest);
	return (truc);
}
/*
int	main(void)
{
	int	fd;
	char	*line;
	int	i;

	i = 1;
	fd = open("get_next_line.c", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("La ligne %d est :%s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}*/
