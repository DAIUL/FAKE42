#include "push_swap.h"

void    ft_arab(t_list_ps **tab, int op, int w)
{
    t_list_ps  *temp;
    t_list_ps  *travel;

    temp = tab[op];
    tab[op] = tab[op]->next;
    temp->next = NULL;
    travel = tab[op];
    while (travel->next)
        travel = travel->next;
    travel->next = temp;
    if (w == 1)
        ft_printf("ra\n");
    if (w == 2)
        ft_printf("rb\n");
}

void    ft_rr(t_list_ps **tab)
{
    ft_arab(tab, 0, 3);
    ft_arab(tab, 1, 3);
    ft_printf("rr\n");
}

void    ft_rarab(t_list_ps **tab, int op, int w)
{
    t_list_ps  *temp;
    t_list_ps  *travel;
    t_list_ps  *ad;

    temp = tab[op];
    travel = tab[op];
    while (travel->next)
    {
        ad = travel;
        travel = travel->next;
    }
    tab[op] = travel;
    ad->next = NULL;
    tab[op]->next = temp;
    if (w == 1)
        ft_printf("rra\n");
    if (w == 2)
        ft_printf("rrb\n");
}

void    ft_rrr(t_list_ps **tab)
{
    ft_rarab(tab, 0, 3);
    ft_rarab(tab, 1, 3);
    ft_printf("rrr\n");
}