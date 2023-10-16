#include "push_swap.h"

void    ft_sab(t_list_ps **tab, int op, int w)
{
    t_list_ps *temp;

    if (tab[op - 1] == NULL || tab[op - 1]->next == NULL)
        return ;
    temp = tab[op - 1];
    tab[op - 1] = tab[op - 1]->next;
    temp->next = tab[op - 1]->next;
    tab[op - 1]->next = temp;
    if (w == 1)
        ft_printf("sa\n");
    if (w == 2)
        ft_printf("sb\n");
}

void    ft_ss(t_list_ps **tab)
{
    ft_sab(tab, 1, 3);
    ft_sab(tab, 2, 3);
    ft_printf("ss\n");
}

void    ft_pa(t_list_ps **tab)
{
    t_list_ps *temp;

    if (tab[1] == NULL)
        return ;
    temp = tab[0];
    tab[0] = tab[1];
    tab[1] = tab[1]->next;
    tab[0]->next = temp;
    ft_printf("pa\n");
}

void    ft_pb(t_list_ps **tab)
{
    t_list_ps *temp;

    if (tab[0] == NULL)
        return ;
    temp = tab[1];
    tab[1] = tab[0];
    tab[0] = tab[0]->next;
    tab[1]->next = temp;
    ft_printf("pb\n");
}