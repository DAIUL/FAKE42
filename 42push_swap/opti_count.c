#include "push_swap.h"

int     a_min_steps(t_list_ps *a, int nb)
{
    int i;
    int size;

    i = 1;
    size = list_len(a);
    while (nb != a->data)
    {
        i++;
        a = a->next;
    }
    if (i > (size/2))
        return (size - (i - 1));
    else
        return (i - 1);
}

int     b_min_steps(t_list_ps *b, int nb)
{
    int i;
    int size;

    i = 1;
    size = list_len(b);
    if ((nb > min_max(b, 2)) || (nb < min_max(b, 1)))
        return (a_min_steps(b, min_max(b, 2)) + 1);
    if (nb > b->data && nb < last_list_data(b))
        return (i);
    while (!(nb > b->next->data && nb < b->data))
    {
        i++;
        b = b->next;
    }
    if (i > (size/2))
        return (size - i);
    else
        return (i);
}

int     idc_steps(t_list_ps **tab, int idc)
{
    int i;

    i = 1;
    while (i < idc)
    {
        tab[0] = tab[0]->next;
        i++;
    }
    return ((a_min_steps(tab[0], tab[0]->data) + b_min_steps(tab[1], tab[0]->data)));
}

int     opti_idc(t_list_ps **tab)
{
    int idc;
    int opti;
    int size;
    int ret;

    idc = 1;
    opti = (a_min_steps(tab[0], tab[0]->data) + b_min_steps(tab[1], tab[0]->data));
    size = list_len(tab[0]);
    while (idc <= opti || size >= (list_len(tab[0]) - (opti - 2)))
    {
        if (idc_steps(tab, idc) < opti)
        {
            opti = idc_steps(tab, idc);
            ret = idc;
        }
        if (idc_steps(tab, size) < opti)
        {
            opti = idc_steps(tab, size);
            ret = size;
        }
        idc++;
        size--;
    }
    return (ret);
}