/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chardigit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:17:21 by qpuig             #+#    #+#             */
/*   Updated: 2023/03/14 19:38:48 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_printstr("(null)"));
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_printdi(int a)
{
	char	s[16];
	int		i;
	int		b;

	i = 0;
	b = 0;
	if (a == -2147483648)
	{
		b += ft_printstr("-2147483648");
		return (b);
	}
	if (a < 0)
	{
		b += ft_printchar('-');
		a *= -1;
	}
	while (a != 0 || i == 0)
	{
		s[i++] = (a % 10) + 48;
		a /= 10;
	}
	while (i)
		b += ft_printchar(s[--i]);
	return (b);
}

int	ft_printudeci(unsigned int a)
{
	char	s[16];
	int		i;
	int		b;

	b = 0;
	i = 0;
	while (a != 0 || i == 0)
	{
		s[i++] = (a % 10) + 48;
		a /= 10;
	}
	while (i)
		b += ft_printchar(s[--i]);
	return (b);
}
