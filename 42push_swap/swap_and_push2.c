#include "push_swap2.h"

void    ft_sab2(t_list_ps **tab, int op)
{
    t_list_ps *temp;

    if (tab[op] == NULL || tab[op]->next == NULL)
        return ;
    temp = tab[op];
    tab[op] = tab[op]->next;
    temp->next = tab[op]->next;
    tab[op]->next = temp;
}

void    ft_ss2(t_list_ps **tab)
{
    ft_sab2(tab, 0);
    ft_sab2(tab, 1);
    ft_printf("ss\n");
}

void    ft_pa2(t_list_ps **tab)
{
    t_list_ps *temp;

    if (tab[1] == NULL)
        return ;
    temp = tab[0];
    tab[0] = tab[1];
    tab[1] = tab[1]->next;
    tab[0]->next = temp;
}

void    ft_pb2(t_list_ps **tab)
{
    t_list_ps *temp;

    if (tab[0] == NULL)
        return ;
    temp = tab[1];
    tab[1] = tab[0];
    tab[0] = tab[0]->next;
    tab[1]->next = temp;
}