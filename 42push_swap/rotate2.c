#include "push_swap2.h"

void    ft_arab2(t_list_ps **tab, int op)
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
}

void    ft_rr2(t_list_ps **tab)
{
    ft_arab2(tab, 0);
    ft_arab2(tab, 1);
}

void    ft_rarab2(t_list_ps **tab, int op)
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
}

void    ft_rrr2(t_list_ps **tab)
{
   ft_rarab2(tab, 0);
   ft_rarab2(tab, 1);
}