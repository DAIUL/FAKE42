#include "push_swap.h"

int     get_nb(t_list_ps *a, int idc)
{
    int i;

    i = 1;
    while (i < idc)
    {
        i++;
        a = a->next;
    }
    return (a->data);
}

int     get_idca(t_list_ps *a, int nb)
{
    int i;

    i = 1;
    while (nb != a->data)
    {
        i++;
        a = a->next;
    }
    return (i);
}

int     get_idcb(t_list_ps *b, int nb)
{
    int i;

    i = 1;
    if ((nb > min_max(b, 2)) || (nb < min_max(b, 1)))
        return (get_idca(b, min_max(b, 2)));
    if (nb > b->data && nb < last_list_data(b))
        return (i);
    while ((b->next && !(nb > b->next->data && nb < b->data)))
    {
        i++;
        b = b->next;
    }
    i++;
    return (i);
}