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

void    zzz(t_philo *p)
{
	if (ft_stop(p))
		return ;
    ft_print(p, 1);
	usleep(p->info->ti_sleep * 1000);
    ft_print(p, 2);
	return ;
}

void    miam(t_philo *p)
{
	if (ft_stop(p))
		return ;
    pthread_mutex_lock(p->fork);
    ft_print(p, 4);
	pthread_mutex_lock(p->nfork);
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

void    *cycle(void *temp)
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

void    create(int ac, char **av)
{
	int		i;
	t_info	*info;
	t_philo	*p;

	info = ft_calloc(1, sizeof(t_info));
	fill_arg(info, av, ac);
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->sleep, NULL);
	pthread_mutex_init(&info->think, NULL);
	pthread_mutex_init(&info->create, NULL);
	pthread_mutex_init(&info->death, NULL);
	pthread_mutex_init(&info->stop, NULL);
	pthread_mutex_init(&info->meal, NULL);
	pthread_mutex_init(&info->full, NULL);
	p = ft_calloc(info->nb_philo, sizeof(t_philo)); 
	info->f = ft_calloc(info->nb_philo, sizeof(pthread_mutex_t));
    i = 0;
	while (i < info->nb_philo)
		pthread_mutex_init(&info->f[i++], NULL);
	i = 0;
	while (i < (info->nb_philo))
    {
		p[i].info = info;
		p[i].nb = i;
		p[i].fork = &info->f[i];
		if (i == info->nb_philo - 1)
			p[i].nfork = &info->f[0];
		else
			p[i].nfork = &info->f[i + 1];
		i++;
    }
    i = -1;
    while (++i < info->nb_philo)
	{
        pthread_create(&p[i].id, NULL, cycle, &p[i]);
    	pthread_create(&p[i].idd, NULL, death_check, &p[i]);
	}
    i = -1;
    while (++i < info->nb_philo)
	{
		pthread_join(p[i].id, NULL);
		pthread_join(p[i].idd, NULL);
	}
	free(p->info->f);
    free(p);
}