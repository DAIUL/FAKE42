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
    pthread_mutex_lock(p->info->sleep);
	printf("%d is sleeping\n", p->nb);
	pthread_mutex_unlock(p->info->sleep);
	usleep(p->info->ti_sleep * 1000);
	pthread_mutex_unlock(p->info->think);
	printf("%d is thinking\n", p->nb);
	pthread_mutex_unlock(p->info->think);
}

void    *miam(t_philo *p)
{
    pthread_mutex_lock(p->fork);
	pthread_mutex_lock(p->nfork);
	printf("%d is eating\n", p->nb);
	usleep(p->info->ti_eat * 1000);
    pthread_mutex_unlock(p->fork);
	pthread_mutex_unlock(p->nfork);
}

void    *cycle(void *temp)
{	
	t_philo	*p;

	p = (t_philo *)temp;
    miam(p);
    zzz(p);
}

void	fill_arg(t_info *info, char **av)
{
	info->nb_philo = ft_atol(av[1]);
	info->ti_think = ft_atol(av[2]);
	info->ti_eat = ft_atol(av[3]);
	info->ti_sleep = ft_atol(av[4]);
}

void    create(char **av)
{
	t_philo	*p;
	t_info	info;
	pthread_mutex_t	*f;
	int		i;

	fill_arg(&info, av);
	pthread_mutex_init(info.eat, NULL);
	pthread_mutex_init(info.sleep, NULL);
    pthread_mutex_init(info.think, NULL);
	p = ft_calloc((int)info.nb_philo, sizeof(t_philo)); 
	f = ft_calloc((int)info.nb_philo, sizeof(pthread_mutex_t));
    i = 0;
	while (i < (int)info.nb_philo)
		pthread_mutex_init(&f[i], NULL);
	i = 0;
	while (i < ((int)info.nb_philo - 1))
    {
        p[i].info = &info;
		p[i].nb = i;
		p[i].fork = &f[i];
		p[i].nfork = &f[i + 1];
		i++;
    }
	p[i].fork = &f[i];
	p[i].nfork = &f[0];
    i = 0;
    while (p[i])
        pthread_create(&p[i].id, NULL, &cycle, &p[i]);
    i = 0;
    while (p[i])
		pthread_join(p[i].id, NULL);
}