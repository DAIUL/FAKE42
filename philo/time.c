/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:53:10 by qpuig             #+#    #+#             */
/*   Updated: 2023/11/01 16:53:10 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	get_milli(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));	
}

int		ft_stop(t_philo *p)
{
    pthread_mutex_lock(&p->info->death);
    pthread_mutex_lock(&p->info->full);
	if (p->info->ilemor == 0 && p->ilerepu == 0)
		return (pthread_mutex_unlock(&p->info->death), pthread_mutex_unlock(&p->info->full), 0);
	else
    	pthread_mutex_unlock(&p->info->death);
    	pthread_mutex_unlock(&p->info->full);
	return (1);
}

void	*death_check(void *temp)
{
	t_philo	*p;

	p = (t_philo *)temp;
	while (!ft_stop(p))
	{
    	pthread_mutex_lock(&p->info->stop);
    	pthread_mutex_lock(&p->info->meal);
		if	((((get_milli() - p->info->start) - p->last_meal) > p->info->ti_think) && !ft_stop(p))
		{
			pthread_mutex_lock(&p->info->print);
    		printf("%llu %d is dead\n", (get_milli() - p->info->start), p->nb);
			pthread_mutex_lock(&p->info->death);
			p->info->ilemor = 1;
			return (pthread_mutex_unlock(&p->info->death), pthread_mutex_unlock(&p->info->print), pthread_mutex_unlock(&p->info->stop), pthread_mutex_unlock(&p->info->meal), (void *)0);
		}
		else if ((p->act_meal == p->info->nb_meal) && !ft_stop(p))
		{
			pthread_mutex_lock(&p->info->print);
    		printf("%llu %d is full\n", (get_milli() - p->info->start), p->nb);
			pthread_mutex_lock(&p->info->full);
			p->ilerepu = 1;
			return (pthread_mutex_unlock(&p->info->full), pthread_mutex_unlock(&p->info->print), pthread_mutex_unlock(&p->info->meal), pthread_mutex_unlock(&p->info->stop), (void *)0);
		}
    	pthread_mutex_unlock(&p->info->stop);
    	pthread_mutex_unlock(&p->info->meal);
	}
	return ((void *)0);
}