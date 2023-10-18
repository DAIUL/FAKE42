#include "push_swap.h"

void    quaso(t_list_ps **tab)
{
    while (get_idca(tab[0], min_max(tab[0], 1)) != 1)
    {
        if (get_idca(tab[0], min_max(tab[0], 1)) <= (list_len(tab[0]) / 2))
            ft_arab(tab, 0, 1);
        else
            ft_rarab(tab, 0, 1);
    }
}

void    push_me_daddy(t_list_ps **tab)
{
    while (get_idca(tab[1], min_max(tab[1], 2)) != 1)
    {
        if (get_idca(tab[1], min_max(tab[1], 2)) <= (list_len(tab[1]) / 2))
            ft_arab(tab, 1, 2);
        else
            ft_rarab(tab, 1, 2);
    }
    while (list_len(tab[1]) > 0)
    {
        if (tab[1]->data < tab[0]->data && tab[1]->data > last_list_data(tab[0]))
            ft_pa(tab);
        else if ((tab[1]->data > min_max(tab[0], 2)) || (tab[1]->data < min_max(tab[0], 1)))
        {
            while (get_idca(tab[0], min_max(tab[0], 1)) != 1)
            {
                if (get_idca(tab[0], min_max(tab[0], 1)) <= (list_len(tab[0]) / 2))
                    ft_arab(tab, 0, 1);
                else
                    ft_rarab(tab, 0, 1);
            }
            ft_pa(tab);
        }
        else
            ft_rarab(tab, 0, 1);
    }
}