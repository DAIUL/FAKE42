#include "push_swap.h"

int     a_min_steps(t_list_ps *a, int nb)
{
    int i;
    int size;

    i = 1;
    size = list_len(a);
    while (a && (nb != a->data))
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

int     dual_move(int idca, int idcb, int sizea, int sizeb)
{
    if ((idca > (sizea/2)) && (idcb > (sizeb/2)))
    {
        if ((sizea - idca) > (sizeb - idcb))
            return (sizea - idca + 2);
        return (sizeb - idcb + 2);
    }
    else if ((idca <= (sizea/2)) && (idcb <= (sizeb/2)))
    {
        if (idca > idcb)
            return (idca);
        return (idcb);
    }
    else if ((idca <= (sizea/2)) && (idcb > (sizeb/2)))
        return(idca + (sizeb - idcb + 1));
    else if ((idca > (sizea/2)) && (idcb <= (sizeb/2)))
        return (idcb + (sizea - idca + 1));
    return (0);
}

int     idc_steps(t_list_ps **tab, int idc)
{
    int i;
    t_list_ps *a;

    i = 1;
    a = tab[0];
    while (i < idc)
    {
        a = a->next;
        i++;
    }
    return (dual_move(get_idca(tab[0], a->data), get_idcb(tab[1], a->data), list_len(tab[0]), list_len(tab[1])));
}

int     opti_idc(t_list_ps **tab)
{
    int idc;
    int opti;
    int size;
    int ret;

    idc = 1;
    ret = 1;
    opti = (idc_steps(tab, idc++));
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