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
    pthread_mutex_t print;
    pthread_mutex_t sleep;
    pthread_mutex_t think;
    pthread_mutex_t create;
    pthread_mutex_t death;
    pthread_mutex_t stop;
    pthread_mutex_t meal;
    pthread_mutex_t full;
	int	nb_philo;
	long long int	ti_eat;
	long long int	ti_sleep;
	long long int	ti_think;
    long long int   nb_meal;
    pthread_mutex_t *f;
    long long int   start;
    int             ilemor;
}               t_info;

typedef struct s_philo
{
    struct s_info   *info;
    pthread_t       id;
    pthread_t       idd;
    int             nb;
    int             ilerepu;
    long long int   act_meal;
    long long int   last_meal;
    pthread_mutex_t *fork;
	pthread_mutex_t	*nfork;
}				t_philo;

void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);
long long int	ft_atol(const char *nptr);
void			fill_arg(t_info *info, char **av, int ac);
long long int	get_milli(void);
void			create(int ac, char **av);
void	        *death_check(void *temp);
void    		miam(t_philo *p);
void    		zzz(t_philo *p);
int		        ft_stop(t_philo *p);
void	        ft_print(t_philo *p, int state);



#endif