/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:55:31 by qpuig             #+#    #+#             */
/*   Updated: 2023/07/17 15:01:09 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <limits.h>
#include "./ft_printf/ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_toudinkou(char *mes, char c)
{
	int		i;
	char	*plugro;

	if (mes == NULL)
	{
		mes = malloc(2);
		mes[0] = c;
		mes[1] = '\0';
		return (mes);
	}
	else
	{
		plugro = malloc((ft_strlen(mes) + 2) * sizeof(char));
		i = 0;
		while (mes[i])
		{
			plugro[i] = mes[i];
			i++;
		}
		plugro[i++] = c;
		plugro[i] = '\0';
		free(mes);
	}
	return (plugro);
}

static void	ft_huston(int signal, siginfo_t *sida, void *osef)
{
	static char	bits = 0;
	static int	decal = 7;
	static char	*mes = NULL;

	(void)osef;
	if (decal >= 0 && signal == SIGUSR1)
		bits = bits | 1 << decal;
	decal--;
	if (decal < 0)
	{
		mes = ft_toudinkou(mes, bits);
		decal = 7;
		if (!bits)
		{
			kill(sida->si_pid, SIGUSR2);
			ft_printf("%s\n", mes);
			free(mes);
			mes = NULL;
			return ;
		}
		bits = 0;
	}
	kill(sida->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sida;

	ft_printf("PID : %i\n", getpid());
	sida.sa_flags = SA_SIGINFO;
	sida.sa_sigaction = ft_huston;
	while (1)
	{
		sigaction(SIGUSR1, &sida, NULL);
		sigaction(SIGUSR2, &sida, NULL);
	}
}
