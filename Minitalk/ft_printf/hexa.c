/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:41:19 by qpuig             #+#    #+#             */
/*   Updated: 2023/03/14 19:44:17 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptrhexa(unsigned long long a)
{
	char	s[16];
	int		i;
	int		b;

	if (!a)
		return (ft_printstr("(nil)"));
	i = 0;
	b = 0;
	b += ft_printstr("0x");
	while (a != 0)
	{
		s[i] = HEXAMIN[a % 16];
		a /= 16;
		i++;
	}
	while (i)
	{
		i--;
		b += ft_printchar(s[i]);
	}
	return (b);
}

int	ft_printhexamin(unsigned int a)
{
	char	s[16];
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (a != 0 || i == 0)
	{
		s[i++] = HEXAMIN[a % 16];
		a /= 16;
	}
	while (i)
		b += ft_printchar(s[--i]);
	return (b);
}

int	ft_printhexamaj(unsigned int a)
{
	char	s[16];
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (a != 0 || i == 0)
	{
		s[i++] = HEXAMAJ[a % 16];
		a /= 16;
	}
	while (i)
		b += ft_printchar(s[--i]);
	return (b);
}
