/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:37:43 by qpuig             #+#    #+#             */
/*   Updated: 2023/08/09 20:53:48 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	char	*truc;

	if (!s1 || !set)
		return (NULL);
	j = (int)ft_strlen(s1) - 1;
	while (ft_strrchr(set, (int)s1[j]) && j > 0)
		j--;
	i = 0;
	while (ft_strchr(set, (int)s1[i]))
		i++;
	truc = ft_substr(s1, (unsigned int)i, (size_t)(j - i + 1));
	return (truc);
}
