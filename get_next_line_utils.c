/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:06:00 by qpuig             #+#    #+#             */
/*   Updated: 2023/02/25 17:05:42 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_check(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return (1);
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	size_t	clatay;
	size_t	i;

	i = 0;
	clatay = ft_strlen(s);
	dup = malloc(clatay + 1 * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*s3;

	if (!s1)
		return (ft_strdup(s2));
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s3[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	s3[ft_strlen(s1) + ft_strlen(s2) + 1] = '\0';
	free(s1);
	return (s3);
}

char	*ft_rest(char *s1, char *s2, char *s3)
{
	int		i;
	int		j;
	char	*s4;

	i = 0;
	while (s1[i] != '\n')
		i++;
	s4 = malloc(ft_strlen(s1) + i + 1 * sizeof(char));
	i = 0;
	while (s1[i])
	{
		s4[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\n')
	{
		s4[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	s4[ft_strlen(s1) + i] = '\0';
	j = 0;
	while (s2[i])
		s3[j++] = s2[i++];
	return (s4);
}
