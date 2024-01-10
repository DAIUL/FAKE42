/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:12:29 by qpuig             #+#    #+#             */
/*   Updated: 2023/02/15 16:56:29 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	m;

	if (n < 0)
	{
		m = -n;
		ft_putchar_fd('-', fd);
	}
	else
		m = n;
	c = m % 10 + 48;
	m /= 10;
	if (m > 0)
		ft_putnbr_fd(m, fd);
	ft_putchar_fd(c, fd);
}
