#include "push_swap.h"

void    ft_arab(t_list_ps *a, int op)
{
    t_list_ps  *temp;
    t_list_ps  *travel;

    temp = a;
    a = a->next;
    temp->next = NULL;
    travel = a;
    while (travel->next)
        travel = travel->next;
    travel->next = temp;
    if (op == 1)
        ft_printf("ra\n");
    if (op == 2)
        ft_printf("rb\n");
}

void    ft_rr(t_list_ps **tab)
{
    ft_arab(tab[0], 3);
    ft_arab(tab[1], 3);
    ft_printf("rr\n");
}

void    ft_rarab(t_list_ps *a, int op)
{
    t_list_ps  *temp;
    t_list_ps  *travel;

    temp = a;
    while (travel->next->next)
        travel = travel->next;
    a = travel->next;
    travel->next = NULL;
    a->next = temp;
    if (op == 1)
        ft_printf("rra\n");
    if (op == 2)
        ft_printf("rrb\n");
}

void    ft_rrr(t_list_ps **tab)
{
    ft_arab(tab[0], 3);
    ft_arab(tab[1], 3);
    ft_printf("rrr\n");
}