/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:06:00 by qpuig             #+#    #+#             */
/*   Updated: 2023/10/19 17:17:16 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_g(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_check_g(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return (1);
	return (0);
}

char	*ft_strdup_g(char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	if (!s || !*s)
		return (NULL);
	dup = malloc((ft_strlen_g(s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	int		i;
	char	*s3;

	if (!s1)
		return (ft_strdup_g(s2));
	s3 = malloc(ft_strlen_g(s1) + ft_strlen_g(s2) + 1 * sizeof(char));
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
		s3[ft_strlen_g(s1) + i] = s2[i];
		i++;
	}
	s3[ft_strlen_g(s1) + i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_free(char *s)
{
	if (!s[0])
	{
		free(s);
		s = NULL;
	}
	return (s);
}
