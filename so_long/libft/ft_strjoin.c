/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:28:31 by qpuig             #+#    #+#             */
/*   Updated: 2023/08/09 20:54:04 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*truc;

	if (!s1 || !s2)
		return (NULL);
	truc = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!truc)
		return (NULL);
	ft_strlcat(truc, s1, (ft_strlen(s1) + 1));
	ft_strlcat(truc, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (truc);
}
