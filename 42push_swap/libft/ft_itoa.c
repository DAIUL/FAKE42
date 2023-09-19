/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:37:55 by qpuig             #+#    #+#             */
/*   Updated: 2023/02/15 13:11:21 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_size(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*truc;
	size_t			i;
	unsigned int	m;

	i = ft_size(n) - 1;
	truc = ft_calloc(i + 2, sizeof(char));
	if (n == 0)
		truc[0] = '0';
	if (!truc)
		return (NULL);
	m = n;
	if (n < 0)
	{
		m = -n;
		truc[0] = '-';
	}
	while (m != 0)
	{
		truc[i] = (m % 10) + '0';
		m /= 10;
		i--;
	}
	return (truc);
}
