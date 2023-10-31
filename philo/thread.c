/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:49:39 by qpuig             #+#    #+#             */
/*   Updated: 2023/10/23 16:49:39 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    *zzz(t_philo *p)
{
    pthread_mutex_lock(&p->info->sleep);
	printf("%d is sleeping\n", p->nb);
	pthread_mutex_unlock(&p->info->sleep);
	usleep(p->info->ti_sleep * 1000);
	pthread_mutex_unlock(&p->info->think);
	printf("%d is thinking\n", p->nb);
	pthread_mutex_unlock(&p->info->think);
	return ((void *)0);
}

void    *miam(t_philo *p)
{
    pthread_mutex_lock(p->fork);
	pthread_mutex_lock(p->nfork);
	printf("%d is eating\n", p->nb);
	usleep(p->info->ti_eat * 1000);
    pthread_mutex_unlock(p->fork);
	pthread_mutex_unlock(p->nfork);
	return ((void *)0);
}

void    *cycle(void *temp)
{	
	t_philo	*p;

	p = (t_philo *)temp;
    pthread_mutex_lock(&p->info->create);
    pthread_mutex_unlock(&p->info->create);
    miam(p);
    zzz(p);
	return ((void *)0);
}

void	fill_arg(t_info *info, char **av)
{
	info->nb_philo = (int)ft_atol(av[1]);
	info->ti_think = ft_atol(av[2]);
	info->ti_eat = ft_atol(av[3]);
	info->ti_sleep = ft_atol(av[4]);
}

void    create(t_glo *glo)
{
	int		i;

	pthread_mutex_init(&glo->info.eat, NULL);
	pthread_mutex_init(&glo->info.sleep, NULL);
	pthread_mutex_init(&glo->info.think, NULL);
	pthread_mutex_init(&glo->info.create, NULL);
	glo->philo = ft_calloc(glo->info.nb_philo, sizeof(t_philo)); 
	glo->info.f = ft_calloc(glo->info.nb_philo, sizeof(pthread_mutex_t));
    i = 0;
	while (i < glo->info.nb_philo)
		pthread_mutex_init(&glo->info.f[i++], NULL);
	i = 0;
	while (i < (glo->info.nb_philo - 1))
    {
		glo->philo[i].info = &glo->info;
		glo->philo[i].nb = i;
		glo->philo[i].fork = &glo->info.f[i];
		glo->philo[i].nfork = &glo->info.f[i + 1];
		i++;
    }
	glo->philo[i].fork = &glo->info.f[i];
	glo->philo[i].nfork = &glo->info.f[0];
    pthread_mutex_lock(&glo->info.create);
    i = -1;
    while (++i < glo->info.nb_philo)
        pthread_create(&glo->philo[i].id, NULL, &cycle, &glo->philo[i]);
    i = -1;
    while (++i < glo->info.nb_philo)
		pthread_join(glo->philo[i].id, NULL);
    pthread_mutex_unlock(&glo->info.create);
}