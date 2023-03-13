/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:41:19 by qpuig             #+#    #+#             */
/*   Updated: 2023/03/13 15:21:29 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptrhexa(unsigned long long a)
{
	char	*s;
	int		i;
	int		b;
	int		oui;

	i = 0;
	b = a;
	while (a < 1)
	{
		a /= 10;
		i++;
	}
	s = malloc(i * sizeof(char));
	oui = i;
	while (b < 1)
	{
		s[i] = HEXAMIN[b % 16];
		i--;
	}
	ft_printstr("0x");
	ft_printstr(s);
	return (oui);
}

int	ft_printhexamin(unsigned int a)
{
	char	*s;
	int		i;
	int		b;
	int		oui;

	i = 0;
	b = a;
	while (a < 1)
	{
		a /= 10;
		i++;
	}
	s = malloc(i * sizeof(char));
	oui = i;
	while (b < 1)
	{
		s[i] = HEXAMIN[b % 16];
		i--;
	}
	ft_printstr(s);
	return (oui);
}

int	ft_printhexamaj(unsigned int a)
{
	char	*s;
	int		i;
	int		b;
	int		oui;

	i = 0;
	b = a;
	while (a < 1)
	{
		a /= 10;
		i++;
	}
	s = malloc(i * sizeof(char));
	oui = i;
	while (b < 1)
	{
		s[i] = HEXAMAJ[b % 16];
		i--;
	}
	ft_printstr(s);
	return (oui);
}
