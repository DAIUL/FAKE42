/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:24:23 by qpuig             #+#    #+#             */
/*   Updated: 2023/03/14 13:14:23 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include<stdio.h>
# include<stdarg.h>
# include<stdlib.h>
# include<string.h>
# include<unistd.h>

# define HEXAMIN "0123456789abcdef"
# define HEXAMAJ "0123456789ABCDEF"

int	ft_printf(const char *s, ...);
int	ft_watisdis(va_list truc, const char c);
int	ft_printchar(int c);
int	ft_printstr(char *s);
int	ft_printptrhexa(unsigned long long a);
int	ft_printdi(int a);
int	ft_printudeci(unsigned int a);
int	ft_printhexamin(unsigned int a);
int	ft_printhexamaj(unsigned int a);
int	ft_printprct(void);

#endif
