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

// ou je suis cense intialiser les philo ?

void    create(void)
{
    pthread_t   p1;
    pthread_t   p2;
    pthread_t   p3;
    pthread_t   p4;
    t_mut   mut;

// boucle de cration en fct de ac ?
// dans ce cas la comment declarer ?

    pthread_create(&p1, NULL, &cycle, NULL);
    pthread_create(&p2, NULL, &cycle, NULL);
    pthread_create(&p3, NULL, &cycle, NULL);
    pthread_create(&p4, NULL, &cycle, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);
    pthread_mutex_init(&mut->eat, NULL);
    pthread_mutex_init(&mut->sleep, NULL);
    pthread_mutex_init(&mut->think, NULL);
}

void    *cycle(void  *) //quelle variable je peux mettre en parametre ?
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