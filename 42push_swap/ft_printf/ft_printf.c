/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:16:12 by qpuig             #+#    #+#             */
/*   Updated: 2023/03/13 15:56:35 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printprct(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_watisdat(va_list truc, const char c)
{
	int	a;

	a = 0;
	if (c == 'c')
		a += ft_printchar(va_arg(truc, int));
	else if (c == 's')
		a += ft_printstr(va_arg(truc, char *));
	else if (c == 'p')
		a += ft_printptrhexa(va_arg(truc, unsigned long long));
	else if (c == 'd' || c == 'i')
		a += ft_printdi(va_arg(truc, int));
	else if (c == 'u')
		a += ft_printudeci(va_arg(truc, unsigned int));
	else if (c == 'x')
		a += ft_printhexamin(va_arg(truc, unsigned int));
	else if (c == 'X')
		a += ft_printhexamaj(va_arg(truc, unsigned int));
	else if (c == '%')
		a += ft_printprct();
	return (a);
}

int	ft_printf(const char *s, ...)
{
	va_list	truc;
	int		i;
	int		itisdis;

	i = 0;
	itisdis = 0;
	va_start(truc, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_printchar(s[i]);
			itisdis++;
		}
		else
		{
			i++;
			itisdis += ft_watisdat(truc, s[i]);
		}
		i++;
	}
	va_end(truc);
	return (itisdis);
}
