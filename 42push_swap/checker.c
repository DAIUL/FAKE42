#include "push_swap2.h"

int     check_sort(t_list_ps *a)
{
    while (a->next)
    {
        if (a->data < a->next->data)
            a = a->next;
        else
            return (0);
    }
    return (1);
}

void    move(t_list_ps **tab, char *lect)
{
    if (ft_strncmp(lect, "pa\n", 3) == 0)
        ft_pa2(tab);
    else if (ft_strncmp(lect, "pb\n", 3) == 0)
        ft_pb2(tab);
    else if (ft_strncmp(lect, "sa\n", 3) == 0)
        ft_sab2(tab, 0);
    else if (ft_strncmp(lect, "sb\n", 3) == 0)
        ft_sab2(tab, 1);
    else if (ft_strncmp(lect, "ss\n", 3) == 0)
        ft_ss2(tab);
    else if (ft_strncmp(lect, "ra\n", 3) == 0)
        ft_arab2(tab, 0);
    else if (ft_strncmp(lect, "rb\n", 3) == 0)
        ft_arab2(tab, 1);
    else if (ft_strncmp(lect, "rr\n", 3) == 0)
        ft_rr2(tab);
    else if (ft_strncmp(lect, "rra\n", 4) == 0)
        ft_rarab2(tab, 0);
    else if (ft_strncmp(lect, "rrb\n", 4) == 0)
        ft_rarab2(tab, 1);
    else if (ft_strncmp(lect, "rrr\n", 4) == 0)
        ft_rrr2(tab);
    else
    {
        free(lect);
        while (tab[0])
        ft_lstclear_ps(tab, 0);
        while (tab[1])
        ft_lstclear_ps(tab, 1);
        ft_error(tab);
    }

}

int     main(int ac, char **av)
{
    char    *lect;
    t_list_ps   *a;
    t_list_ps   *b;
    t_list_ps   **tab;

    a = NULL;
    b = NULL;
    tab = ft_calloc(2, sizeof(t_list_ps *));
    a += 0;
    if (ac < 2)
    {
        free(tab);
        return (0);
    }
    if (ac == 2)
        a = ft_soloparam(av[1], tab, ac);
    if (ac > 2)
        a = ft_multiparam(av, tab, ac);
    tab[0] = a;
    tab[1] = b;
    lect = "oui";
    while (lect)
    {
        lect = get_next_line(0);
        if (lect)
            move(tab, lect);
        free(lect);
    }
    if ((check_sort(tab[0]) == 0) || (list_len(tab[1]) != 0))
        ft_printf("KO\n");
    else
        ft_printf("OK\n");
    while (tab[0])
        ft_lstclear_ps(tab, 0);
    while (tab[1])
        ft_lstclear_ps(tab, 1);
    free(tab);
    return (0);
}