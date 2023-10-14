#include "push_swap.h"

void     do_steps(t_list_ps *a, int idc, int op)
{
    int i;
    int size;
    int min;

    i = 0;
    size = list_len(a);
    min = a_min_steps(a, get_nb(a, idc));
    while (i < min)
    {
        ft_printf("i:%d\n", i);
        ft_printf("min_steps:%d\n", min);
        if (idc <= (size/2))
            ft_arab(a, op);
        else
        {
            while (a)
            {
                ft_printf("%d\n", a->data);
                a = a->next;
            }
            ft_rarab(a, op);
        }
    }
}

void     sync_move(int idca, int idcb, int sizea, int sizeb, t_list_ps **tab)
{
    int i;
    t_list_ps *a;
    t_list_ps *b;
    int min;


    a = tab[0];
    b = tab[1];
    i = 0;
    min = a_min_steps(a, get_nb(a, idca));
    if ((idca > (sizea/2)) && (idcb > (sizeb/2)))
    {
        if (idca <= idcb)
        {
            while (i < (a_min_steps(b, get_nb(b, idcb))))
            {
                ft_printf("i:%d\n", i);
                ft_printf("idcb min steps:%d\n", a_min_steps(b, get_nb(b, idcb)));
                ft_rrr(tab);
                i++;
            }
            if (idca < idcb)
                idca += i;
            do_steps(a, idca, 1);
            return ;
        }
        min = a_min_steps(a, get_nb(a, idca));
        while (i < min) //crash ne rerentre pas mis ne sort pas
        {
            ft_printf("i:%d\n", i);
            ft_printf("idca min steps:%d\n", a_min_steps(a, get_nb(a, idca)));
            ft_rrr(tab);
            i++;
            ft_printf("idcb:%d\n", idcb);
        }
        ft_printf("idcb:%d\n", idcb);
        idcb += i;
        do_steps(b  , idcb, 2);
        return ;
    }
    else if ((idca <= (sizea/2)) && (idcb <= (sizeb/2)))
    {
        if (idca >= idcb)
        {
            while (i < (a_min_steps(b, idcb)))
            {
                ft_rr(tab);
                i++;
            }
            if (idca > idcb)
                idca -= i;
            do_steps(a, idca, 1);
            return ;
        }
        while (i < (a_min_steps(a, idca)))
        {
            ft_rr(tab);
            i++;
        }
        idcb -= i;
        do_steps(b, idcb, 2);
        return ;
    }
    else if (((idca <= (sizea/2)) && (idcb > (sizeb/2))) || ((idca > (sizea/2)) && (idcb <= (sizeb/2))))
        {
            do_steps(a, idca, 1);
            do_steps(b, idcb, 2);
        }
    return ;
}

void    sort_idc(t_list_ps **tab, int idc)
{
    int idca;
    int idcb;
    t_list_ps   *a;
    t_list_ps   *b;

    a = tab[0];
    b = tab[1];
    idca = get_idca(a, get_nb(a, idc));
    idcb = get_idcb(b, get_nb(a, idc));
    sync_move(idca, idcb, list_len(a), list_len(b), tab);
    ft_pb(tab);
}

/*void    sort_last_three(t_list_ps *a)
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
}*/

void    push_start(t_list_ps **tab)
{
    ft_pb(tab);
    ft_pb(tab);
    if (tab[1]->data < tab[1]->next->data)
        ft_sab(tab[1], 2);
}