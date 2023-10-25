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

// void    *routine(void *osef)
// {
//     (void)osef;
//     printf("Yacine est raciste\n");
//     sleep(2);
//     printf("Yacine a triche\n");
//     return (osef);
// }

// void    threads_test(void)
// {
//     pthread_t   test;
//     pthread_t   test2;

//     pthread_create(&test, NULL, &routine, NULL);
//     pthread_create(&test2, NULL, &routine, NULL);
//     pthread_join(test, NULL);
//     pthread_join(test2, NULL);
// }

###########################################################

void	fill_arg(t_mut *info, char **av)
{
	info->nb_philo = ft_atol(av[1]);
	info->ti_think = ft_atol(av[2]);
	info->ti_eat = ft_atol(av[3]);
	info->ti_sleep = ft_atol(av[4]);
}

void    create(char **av) //si tu peux pas tout initialsier ici fait le dans le main et envoies le pointeur de la struct en parametre de create
{
	t_philo	*p;
	t_mut	info;
	int		i;

	fill_arg(&info, av);
	pthread_mutex_init(&mut->eat, NULL);
	pthread_mutex_init(&mut->sleep, NULL);
    pthread_mutex_init(&mut->think, NULL);
	p = ft_calloc((int)info->nb_philo, sizeof(t_philo)); 
    i = 0;
	while (i < (int)info->nb_philo)
    {
        p[i]->info = &info;
		p[i]->nb = i;
    }
    i = 0;
    while (p[i])
        pthread_create(&p[i]->id, NULL, &cycle, &p[i]);
    i = 0;
    while (p[i])
		pthread_join(p[i]->id, NULL);
}

void    *cycle(void  *p)
{	
    miam();
    zzz();
    hmmm();
}

void    *miam(void)
{
    pthread_mutex_lock(&mut->eat);
    // action de manger miam miam
    pthread_mutex_unlock(&mut->eat);
}

void    *zzz(void)
{
    pthread_mutex_lock(&mut->sleep);
    // action de dormir zzz zzz
    pthread_mutex_unlock(&mut->sleep);
}

void    *hmmm(void)
{
    pthread_mutex_lock(&mut->think);
    // action de penser hmm hmm
    pthread_mutex_unlock(&mut->think);
}