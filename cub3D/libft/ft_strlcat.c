/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:03:38 by qpuig             #+#    #+#             */
/*   Updated: 2023/08/09 20:54:02 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	if ((!dst || !src) && size == 0)
		return (0);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (!size)
		return (srclen);
	i = 0;
	if ((size < dstlen))
		return (srclen + size);
	while (dstlen + i < size - 1 && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
