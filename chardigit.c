/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chardigit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:17:21 by qpuig             #+#    #+#             */
/*   Updated: 2023/03/13 16:05:04 by qpuig            ###   ########.fr       */
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

int	ft_size(int a)
{
	int	i;

	i = 0;
	while (a != 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int	ft_printdi(int a)
{
	char	*s;
	int		i;
	int		b;
	int		oui;

	i = ft_size(a);
	if (a < 0)
	{
		i++;
		s = malloc(i * sizeof(char));
		s[0] = '-';
		a *= -1;
	}
	else
		s = malloc(i * sizeof(char));
	b = a;
	oui = i;
	while (b > 1)
	{
		s[i] = (b % 10) + 48;
		i--;
	}
	ft_printstr(s);
	return (oui);
}

int	ft_printudeci(unsigned int a)
{
	char	*s;
	int		i;
	int		b;
	int		oui;

	b = a;
	while (a > 1)
	{
		a /= 10;
		i++;
	}
	s = malloc(i * sizeof(char));
	oui = i;
	while (b > 1)
	{
		s[i] = (b % 10) + 48;
		i--;
	}
	ft_printstr(s);
	return (oui);
}
