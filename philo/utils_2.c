/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:33:12 by qpuig             #+#    #+#             */
/*   Updated: 2023/11/10 18:32:51 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	non_la_c_chiant(t_philo *p)
{
	pthread_mutex_lock(&p->info->print);
	printf("%llu philo %d is dead\n", (get_milli() - p->info->start),
		(p->nb + 1));
}

void	process(t_philo *p)
{
	int	i;

	i = -1;
	while ((++i < p->info->nb_philo) && (p->info->nb_philo != 1))
	{
		pthread_create(&p[i].id, NULL, &cycle, &p[i]);
		pthread_create(&p[i].idd, NULL, &death_check, &p[i]);
	}
	i = -1;
	while ((++i < p->info->nb_philo) && (p->info->nb_philo != 1))
	{
		pthread_join(p[i].id, NULL);
		pthread_join(p[i].idd, NULL);
	}
	if (p->info->nb_philo == 1)
	{
		pthread_create(&p[i].id, NULL, &tout_seul, &p[i]);
		pthread_join(p[i].id, NULL);
	}
}

void	setup(t_info *info, int ac, char **av)
{
	fill_arg(info, av, ac);
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->sleep, NULL);
	pthread_mutex_init(&info->think, NULL);
	pthread_mutex_init(&info->create, NULL);
	pthread_mutex_init(&info->death, NULL);
	pthread_mutex_init(&info->stop, NULL);
	pthread_mutex_init(&info->meal, NULL);
	pthread_mutex_init(&info->full, NULL);
}

int	all_unlock(t_philo *p)
{
	if (ft_stop(p) && (p->nb % 2 == 0))
		return (pthread_mutex_unlock(p->fork), 0);
	else if (ft_stop(p) && (p->nb % 2 != 0))
		return (pthread_mutex_unlock(p->nfork), 0);
	return (1);
}

void	destroy(t_philo *p)
{
	int	i;

	pthread_mutex_destroy(&p->info->print);
	pthread_mutex_destroy(&p->info->sleep);
	pthread_mutex_destroy(&p->info->think);
	pthread_mutex_destroy(&p->info->create);
	pthread_mutex_destroy(&p->info->death);
	pthread_mutex_destroy(&p->info->stop);
	pthread_mutex_destroy(&p->info->meal);
	pthread_mutex_destroy(&p->info->full);
	i = 0;
	while (i < p->info->nb_philo)
		pthread_mutex_destroy(&p->info->f[i++]);
	free(p->info->f);
	free(p->info);
	free(p);
}
