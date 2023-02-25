/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:12:18 by qpuig             #+#    #+#             */
/*   Updated: 2023/02/25 17:04:10 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*truc;
	char		*bufs;
	static char	*rest;
	int			lecture;

	lecture = 1;
	bufs = malloc(BUFFER_SIZE + 1 * sizeof(char));
	rest = malloc(BUFFER_SIZE + 1 * sizeof(char));
	while (ft_check(truc, '\n') == 0)
	{
		lecture = read(fd, bufs, BUFFER_SIZE);
		if (ft_check(bufs, '\n') == 1)
			truc = ft_rest(truc, bufs, rest);
		else
			truc = ft_strjoin(truc, bufs);
	}
	free(bufs);
	if (lecture == 0)
		free(rest);
	return (truc);
}
