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

void	*death_check(void *temp)
{
	t_philo	*p;

	p = (t_philo *)temp;
	while (((p->info->nb_meal == -1) || (p->act_meal < p->info->nb_meal)) && (p->info->ilemor == 0))
	{
		if	((get_milli() - p->last_meal) < p->info->ti_think)
		{
    		pthread_mutex_lock(&p->info->death);
    		pthread_mutex_lock(&p->info->eat);
			printf("%llu %d is dead\n", (get_milli() - p->info->start), p->nb);
    		pthread_mutex_unlock(&p->info->eat);
			p->info->ilemor = 1;
    		pthread_mutex_unlock(&p->info->death);
		}
	}
	return ((void *)0);
}