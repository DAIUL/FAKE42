#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>

typedef struct s_list_ps
{
    struct s_list_ps*   next;
    int     data;
}               t_list_ps;


void    ft_sab(t_list_ps **tab, int op, int w);
void    ft_ss(t_list_ps** tab);
void    ft_pa(t_list_ps** tab);
void    ft_pb(t_list_ps** tab);
void    ft_arab(t_list_ps **tab, int op, int w);
void    ft_rr(t_list_ps **tab);
void    ft_rarab(t_list_ps **tab, int op, int w);
void    ft_rrr(t_list_ps **tab);
int     ft_check(char **s, t_list_ps **tab, int ac);
int     *ft_big_atoi(char **s, t_list_ps **tab, int ac);
int     ft_strlen_ps(char **s);
void    sort_last_three(t_list_ps **tab, int op);
void    push_start(t_list_ps **tab);
int     list_len(t_list_ps *a);
int     last_list_data(t_list_ps *b);
int     min_max(t_list_ps *b, int idc);
int     a_min_steps(t_list_ps *a, int nb);
int     b_min_steps(t_list_ps *b, int nb);
int     idc_steps(t_list_ps **tab, int idc);
int     opti_idc(t_list_ps **tab);
t_list_ps	*ft_lstnew_ps(int data);
void	ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new);
long long int	ft_atol(const char *nptr);
void    ft_error(t_list_ps **tab);
t_list_ps	*ft_lstlast_ps(t_list_ps *lst);
int     get_idca(t_list_ps *a, int nb);
int     get_idcb(t_list_ps *b, int nb);
int     dual_move(int idca, int idcb, int sizea, int sizeb);
void    sort_idc(t_list_ps **tab, int idc);
void    sync_move(int idca, int idcb, int sizea, int sizeb, t_list_ps **tab);
void     do_steps(t_list_ps **tab, int idc, int op, int w);
int     get_nb(t_list_ps *a, int idc);
void    push_me_daddy(t_list_ps **tab);
void    quaso(t_list_ps **tab);
void	ft_lstclear_ps(t_list_ps **tab, int op);
void	ft_free_params(char **params);
int     already_sort(t_list_ps *a   );
t_list_ps  *ft_multiparam(char **params, t_list_ps **tab, int ac);
t_list_ps  *ft_soloparam(char *monoparam, t_list_ps** tab, int ac);

#endif