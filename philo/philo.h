#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_mut
{
    pthread_mutex_t *eat;
    pthread_mutex_t *sleep;
    pthread_mutex_t *think;
    pthread_mutex_t *fork;
}               t_mut;

void    *routine(void *osef);
void    threads_test(void);

#endif