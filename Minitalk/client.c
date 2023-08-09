/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:43:05 by qpuig             #+#    #+#             */
/*   Updated: 2023/04/21 10:53:04 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "./ft_printf/ft_printf.h"

int	g_glo;

int	ft_atoi(char *nptr)
{
	int	i;
	int	sign;
	int	vret;

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
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		vret = vret * 10 + (nptr[i] - 48);
		i++;
	}
	return (vret * sign);
}

void	ft_change(int signal)
{
	if (signal == SIGUSR1)
		g_glo = 1;
	if (signal == SIGUSR2)
	{
		ft_printf("Message received");
		exit(EXIT_SUCCESS);
	}
}

void	coupe_decale(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_glo = 0;
		if (c & (1 << i))
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		i--;
		while (g_glo == 0)
			usleep(1);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	pid = ft_atoi(argv[1]);
	if ((pid <= 0) || (argc != 3))
	{
		ft_printf("Y'a un probleme la concentre toi\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	signal(SIGUSR1, &ft_change);
	signal(SIGUSR2, &ft_change);
	if (argc == 3)
	{
		while (argv[2][i])
		{
			coupe_decale(argv[2][i], pid);
			i++;
		}
		coupe_decale(0, pid);
	}
}
