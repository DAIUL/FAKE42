#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_list_ps
{
    struct s_list_ps*   next;
    int     data;
}               t_list_ps;


void    ft_sab(t_list_ps* a, int op);
void    ft_ss(t_list_ps** tab);
void    ft_pa(t_list_ps** tab);
void    ft_pb(t_list_ps** tab);
void    ft_arab(t_list_ps *a, int op);
void    ft_rr(t_list_ps **tab);
void    ft_rarab(t_list_ps *a, int op);
void    ft_rrr(t_list_ps **tab);
int     *ft_big_atoi(char **s);
int     ft_check(char **s);
void    sort_last_three(t_list_ps *a);
void    push_start(t_list_ps **tab);

#endif