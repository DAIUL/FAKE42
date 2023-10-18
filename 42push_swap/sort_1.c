#include "push_swap.h"

void     do_steps(t_list_ps **tab, int idc, int op, int w)
{
    int i;
    int size;
    int min;

    i = 0;
    size = list_len(tab[op]);
    min = a_min_steps(tab[op], get_nb(tab[op], idc));
    while (i < min)
    {
        if (idc <= (size/2))
            ft_arab(tab, op, w);
        else
            ft_rarab(tab, op, w);
        i++;
    }
}

void     sync_move(int idca, int idcb, int sizea, int sizeb, t_list_ps **tab)
{
    int i;
    int min;

    i = 0;
    min = a_min_steps(tab[0], get_nb(tab[0], idca));
    if ((idca > (sizea/2)) && (idcb > (sizeb/2)))
    {
         if ((sizea - idca) >= (sizeb - idcb))
        {
            while (i < (a_min_steps(tab[1], get_nb(tab[1], idcb))))
            {
                ft_rrr(tab);
                i++;
            }
            if ((sizea - idca) > (sizeb - idcb))
                idca += i;
            else if ((sizea - idca) == (sizeb - idcb))
                idca = 1;
            do_steps(tab, idca, 0, 1);
            return ;
        }
        min = a_min_steps(tab[0], get_nb(tab[0], idca));
        while (i < min)
        {
            ft_rrr(tab);
            i++;
        }
        idcb += i;
        do_steps(tab, idcb, 1, 2);
        return ;
    }
    else if ((idca <= (sizea/2)) && (idcb <= (sizeb/2)))
    {
        if (idca >= idcb)
        {
            while (i < (a_min_steps(tab[1], idcb)))
            {
                ft_rr(tab);
                i++;
            }
            if (idca > idcb)
                idca -= i;
            else if (idca == idcb)
                idca = 1;
            do_steps(tab, idca, 0, 1);
            return ;
        }
        while (i < (a_min_steps(tab[0], idca)))
        {
            ft_rr(tab);
            i++;
        }
        idcb -= i;
        do_steps(tab, idcb, 1, 2);
        return ;
    }
    else if (((idca <= (sizea/2)) && (idcb > (sizeb/2))) || ((idca > (sizea/2)) && (idcb <= (sizeb/2))))
        {
            do_steps(tab, idca, 0, 1);
            do_steps(tab, idcb, 1, 2);
        }
    return ;
}

void    sort_idc(t_list_ps **tab, int idc)
{
    int idca;
    int idcb;

    idca = get_idca(tab[0], get_nb(tab[0], idc)); 
    idcb = get_idcb(tab[1], get_nb(tab[0], idc));  
    sync_move(idca, idcb, list_len(tab[0]), list_len(tab[1]), tab);
    ft_pb(tab);
}

void    sort_last_three(t_list_ps **tab, int op)
{
    if ((tab[op]->data > tab[op]->next->data) && (tab[op]->data > tab[op]->next->next->data))
    {
        ft_arab(tab, 0, 1);
        if (tab[op]->data > tab[op]->next->data)
            ft_sab(tab, 0, 1);
    }
    if ((tab[op]->data < tab[op]->next->data) && (tab[op]->next->data > tab[op]->next->next->data))
    {
        if (tab[op]->data > tab[op]->next->next->data)
            ft_rarab(tab, 0, 1);
        else
        {
            ft_sab(tab, 0, 1);
            ft_arab(tab, 0, 1);
        }
    }
    if ((tab[op]->next->next->data > tab[op]->next->data) && (tab[op]->next->next->data > tab[op]->data))
    {
        if (tab[op]->data > tab[op]->next->data)
            ft_sab(tab, 0, 1);
    }
}

void    push_start(t_list_ps **tab)
{
    ft_pb(tab);
    ft_pb(tab);
    if (tab[1]->data < tab[1]->next->data)
        ft_sab(tab, 1, 2);
}