/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:49:19 by qpuig             #+#    #+#             */
/*   Updated: 2023/02/07 17:23:01 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	temp;
	void	*truc;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	temp = (size_t)(nmemb * size);
	if (nmemb != temp / size || size != temp / nmemb)
		return (NULL);
	truc = malloc(nmemb * size);
	if (truc == NULL)
		return (NULL);
	ft_bzero(truc, (nmemb * size));
	return (truc);
}
