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

void    *routine(void *osef)
{
    (void)osef;
    printf("Yacine est raciste\n");
    sleep(2);
    printf("Yacine a triche\n");
    return (osef);
}

void    threads_test(void)
{
    pthread_t   test;
    pthread_t   test2;

    pthread_create(&test, NULL, &routine, NULL);
    pthread_create(&test2, NULL, &routine, NULL);
    pthread_join(test, NULL);
    pthread_join(test2, NULL);
}
