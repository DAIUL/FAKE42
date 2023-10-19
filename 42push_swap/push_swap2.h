#ifndef PUSH_SWAP2_H

# define PUSH_SWAP2_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <limits.h>

typedef struct s_list_ps
{
    struct s_list_ps*   next;
    int     data;
}               t_list_ps;


void    ft_sab2(t_list_ps **tab, int op);
void    ft_ss2(t_list_ps** tab);
void    ft_pa2(t_list_ps** tab);
void    ft_pb2(t_list_ps** tab);
void    ft_arab2(t_list_ps **tab, int op);
void    ft_rr2(t_list_ps **tab);
void    ft_rarab2(t_list_ps **tab, int op);
void    ft_rrr2(t_list_ps **tab);
int     ft_check(char **s, t_list_ps **tab, int ac);
int     *ft_big_atoi(char **s, t_list_ps **tab, int ac);
int     ft_strlen_ps(char **s);
int     list_len(t_list_ps *a);
t_list_ps	*ft_lstnew_ps(int data);
void	ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new);
long long int	ft_atol(const char *nptr);
void    ft_error(t_list_ps **tab);
t_list_ps	*ft_lstlast_ps(t_list_ps *lst);
void	ft_lstclear_ps(t_list_ps **tab, int op);
void	ft_free_params(char **params);
t_list_ps  *ft_soloparam(char *monoparam, t_list_ps** tab, int ac);
t_list_ps  *ft_multiparam(char **params, t_list_ps **tab, int ac);

#endif