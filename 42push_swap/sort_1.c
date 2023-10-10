#include "push_swap.h"

void    sort_last_three(t_list_ps *a)
{
    if ((a->data > a->next->data) && (a->data > a->next->next->data))
    {
        ft_arab(a, 1);
        if (a->data > a->next->data)
            ft_sab(a, 1);
    }
    if ((a->data < a->next->data) && (a->next->data > a->next->next->data))
    {
        if (a->data > a->next->next->data)
            ft_rarab(a, 1);
        else
        {
            ft_sab(a, 1);
            ft_arab(a, 1);
        }
    }
    if ((a->next->next->data > a->next->data) && (a->next->next->data > a->data))
    {
        if (a->data > a->next->data)
            ft_sab(a, 1);
    }
}

void    push_start(t_list_ps **tab)
{
    ft_pb(tab);
    ft_pb(tab);
    if (tab[1]->data < tab[1]->next->data)
        ft_sab(tab[1], 2);
}