#include "push_swap.h"

t_list_ps  *ft_multiparam(char **params, t_list_ps **tab, int ac)
{
    int     i;
    t_list_ps   *a;

    i = 1;
    if (ft_check(params, tab, ac) == 0)
        return (ft_error(tab), NULL);
    a = ft_lstnew_ps(ft_atoi(params[i++]));
    while (params[i])
        ft_lstadd_back_ps(&a, ft_lstnew_ps(ft_atoi(params[i++])));
    return (a);
}

t_list_ps  *ft_soloparam(char *monoparam, t_list_ps** tab, int ac)
{
    char    **params;
    int     i;
    t_list_ps   *a;

    i = 0;
    params = ft_split(monoparam, ' ');
    (void)tab;
    if (ft_check(params, tab, ac) == 0)
    {
        ft_free_params(params);
        return (ft_error(tab), NULL);
    }   
    a = ft_lstnew_ps(ft_atoi(params[i]));
    free(params[i++]);
    while (params[i])
    {
        ft_lstadd_back_ps(&a, ft_lstnew_ps(ft_atoi(params[i])));
        free(params[i++]);
    }
    return (free(params[i]), free(params), a);
}

/*t_list_ps   *push_swap(t_list_ps **tab)
{
    int opti;

    opti = opti_idc(tab);

}*/

int    main(int ac, char **av)
{
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
    if (already_sort(tab[0]) == 1)
    {
        while (tab[0])
            ft_lstclear_ps(tab, 0);
        while (tab[1])
            ft_lstclear_ps(tab, 1);
        free(tab);
        return (0);
    }
    if (list_len(tab[0]) == 2)
    {
        if (tab[0]->data > tab[0]->next->data)
            ft_sab(tab, 0, 1);
        while (tab[0])
            ft_lstclear_ps(tab, 0);
        free(tab);
        return (0);
    }
    if (list_len(tab[0]) == 3)
    {
        sort_last_three(tab, 0);
        while (tab[0])
            ft_lstclear_ps(tab, 0);
        free(tab);
        return (0); 
    }
    if (list_len(tab[0]) == 4)
        ft_pb(tab);
    if (list_len(tab[0]) >= 5)
    {
        push_start(tab);
        while (list_len(tab[0]) > 3)
            sort_idc(tab, opti_idc(tab));
    }
    sort_last_three(tab, 0);
    push_me_daddy(tab);
    quaso(tab);
    while (tab[0])
        ft_lstclear_ps(tab, 0);
    while (tab[1])
        ft_lstclear_ps(tab, 1);
    free(tab);
    return (0); 
}
