/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:22:27 by qpuig             #+#    #+#             */
/*   Updated: 2023/02/15 15:38:24 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*truc;

	i = 0;
	if (!s)
		return (NULL);
	truc = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!truc)
		return (NULL);
	while (s[i] && i < ft_strlen(s))
	{
		truc[i] = f(i, s[i]);
		i++;
	}
	return (truc);
}
