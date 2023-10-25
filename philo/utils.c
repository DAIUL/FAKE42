/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:10:56 by qpuig             #+#    #+#             */
/*   Updated: 2023/10/25 16:10:56 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

long long int	ft_atol(const char *nptr)
{
	int	i;
	int	sign;
	long long int	vret;

	i = 0;
	sign = 1;
	vret = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ((nptr[i] >= 48 && nptr[i] <= 57))
	{
		vret = vret * 10 + (nptr[i] - 48);
		i++;
	}
	return (vret * sign);
}