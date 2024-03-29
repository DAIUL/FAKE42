/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:49:39 by qpuig             #+#    #+#             */
/*   Updated: 2023/11/10 14:58:47 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	zzz(t_philo *p)
{
	if (ft_stop(p))
		return ;
	ft_print(p, 1);
	usleep(p->info->ti_sleep * 1000);
	if (ft_stop(p))
		return ;
	ft_print(p, 2);
	return ;
}

void	miam(t_philo *p)
{
	if (ft_stop(p))
		return ;
	if (p->nb % 2 == 0) 
		pthread_mutex_lock(p->fork);
	else
		pthread_mutex_lock(p->nfork);
	ft_print(p, 4);
	if (all_unlock(p) == 0)
		return ;
	if (p->nb % 2 == 0) 
		pthread_mutex_lock(p->nfork);
	else
		pthread_mutex_lock(p->fork);
	ft_print(p, 4);
	pthread_mutex_lock(&p->info->stop);
	p->last_meal = (get_milli() - p->info->start);
	pthread_mutex_unlock(&p->info->stop);
	ft_print(p, 3);
	usleep(p->info->ti_eat * 1000);
	pthread_mutex_unlock(p->fork);
	pthread_mutex_unlock(p->nfork);
	pthread_mutex_lock(&p->info->meal);
	p->act_meal++;
	pthread_mutex_unlock(&p->info->meal);
	return ;
}

void	*cycle(void *temp)
{
	t_philo	*p;

	p = (t_philo *)temp;
	if ((p->nb % 2) == 0)
		usleep((p->info->ti_eat / 10) * 1000);
	while (!ft_stop(p))
	{
		miam(p);
		zzz(p);
	}
	return ((void *)0);
}

void	fill_arg(t_info *info, char **av, int ac)
{
	info->nb_philo = (int)ft_atol(av[1]);
	info->ti_think = ft_atol(av[2]);
	info->ti_eat = ft_atol(av[3]);
	info->ti_sleep = ft_atol(av[4]);
	info->start = get_milli();
	info->ilemor = 0;
	if (ac == 6)
		info->nb_meal = ft_atol(av[5]);
	else
		info->nb_meal = -1;
}

void	create(int ac, char **av)
{
	int		i;
	t_info	*info;
	t_philo	*p;

	info = ft_calloc(1, sizeof(t_info));
	setup(info, ac, av);
	p = ft_calloc(info->nb_philo, sizeof(t_philo)); 
	info->f = ft_calloc(info->nb_philo, sizeof(pthread_mutex_t));
	i = 0;
	while (i < info->nb_philo)
		pthread_mutex_init(&info->f[i++], NULL);
	i = -1;
	while (++i < (info->nb_philo))
	{
		p[i].info = info;
		p[i].nb = i;
		p[i].fork = &info->f[i];
		if (i == info->nb_philo - 1)
			p[i].nfork = &info->f[0];
		else
			p[i].nfork = &info->f[i + 1];
	}
	all_unlock(p);
	process(p);
	destroy(p);
}
