#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info
{
    pthread_mutex_t eat;
    pthread_mutex_t sleep;
    pthread_mutex_t think;
    pthread_mutex_t create;
	int	nb_philo;
	long long int	ti_eat;
	long long int	ti_sleep;
	long long int	ti_think;
    pthread_mutex_t *f;
    long long int   start;
}               t_info;

typedef struct s_philo
{
    struct s_info   *info;
    pthread_t       id;
    int             nb;
    pthread_mutex_t *fork;
	pthread_mutex_t	*nfork;
}				t_philo;

void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);
long long int	ft_atol(const char *nptr);
void			fill_arg(t_info *info, char **av);
long long int	get_milli(void);
void			create(char **av);
void    		*miam(t_philo *p);
void    		*zzz(t_philo *p);

#endif