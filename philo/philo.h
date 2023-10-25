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
	long long int	nb_philo;
	long long int	ti_eat;
	long long int	ti_sleep;
	long long int	ti_think;
}               t_mut;

typedef struct s_philo
{
    struct s_mut   *mutex;
    pthread_t       id;
    int             nb;
}				t_philo;

void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);
long long int	ft_atol(const char *nptr);

#endif