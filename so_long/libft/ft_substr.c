/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:46:25 by qpuig             #+#    #+#             */
/*   Updated: 2023/02/15 12:20:25 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*truc;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) < ft_strlen(s))
		truc = (char *)ft_calloc(len + 1, sizeof(char));
	else
		truc = (char *)ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	if (!truc)
		return (NULL);
	j = 0;
	while (j < len && s[start])
	{
		truc[j] = s[start];
		start++;
		j++;
	}
	truc[j] = '\0';
	return (truc);
}
