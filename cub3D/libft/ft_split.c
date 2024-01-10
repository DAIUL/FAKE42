/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:24:59 by qpuig             #+#    #+#             */
/*   Updated: 2023/08/09 20:54:28 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nbmot(const char *s, char c)
{
	int				i;
	unsigned int	nbmot;

	i = 0;
	nbmot = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			nbmot++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nbmot);
}

static char	**ft_circoncision(const char *s, char c, char **truc, size_t j)
{
	unsigned int	i;
	size_t			k;

	j = 0;
	k = 0;
	while (s[j])
	{
		i = j;
		while (s[j] == c)
		{
			i++;
			j++;
		}
		while (s[j] != c && s[j])
			j++;
		if (j != i)
		{
			truc[k++] = ft_substr(s, i, (size_t)(j - i));
			if (!truc[k - 1])
				return (NULL);
		}
	}
	truc[k] = NULL;
	return (truc);
}

char	**ft_split(const char *s, char c)
{
	char			**truc;
	size_t			j;

	j = 0;
	if (!s)
		return (NULL);
	truc = ft_calloc(ft_nbmot(s, c) + 1, sizeof(char *));
	if (!truc)
		return (NULL);
	truc = ft_circoncision(s, c, truc, j);
	return (truc);
}
