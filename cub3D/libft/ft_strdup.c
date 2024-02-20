/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:13:15 by qpuig             #+#    #+#             */
/*   Updated: 2024/02/20 11:22:40 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
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

char	*ft_strndup(const char *s, int i, int n)
{
	char	*dup;
	size_t	clatay;
	int		j;

	j = 0;
	clatay = ft_strlen(s);
	dup = malloc(clatay + 1 * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (s[i] && n > 0)
	{
		dup[j++] = s[i++];
		n--;
	}
	dup[j] = '\0';
	return (dup);
}
