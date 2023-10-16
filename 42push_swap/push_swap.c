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
        return (ft_error(tab), NULL);
    a = ft_lstnew_ps(ft_atoi(params[i++]));
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
    t_list_ps   *temp;
    t_list_ps   *retemp;

    a = NULL;
    b = NULL;
    tab = ft_calloc(2, sizeof(t_list_ps *));
    a += 0;
    if (ac == 2)
        a = ft_soloparam(av[1], tab, ac);
    if (ac > 2)
        a = ft_multiparam(av, tab, ac);
    tab[0] = a;
    tab[1] = b;
    push_start(tab);
    sort_idc(tab, opti_idc(tab));
    sort_idc(tab, opti_idc(tab));
    sort_idc(tab, opti_idc(tab));
    sort_idc(tab, opti_idc(tab));
    temp = tab[0];
    retemp = tab[1];
    ft_printf("pile A\n");
    while (temp)
    {
        ft_printf("%d\n", temp->data);
        temp = temp->next;
    }
    ft_printf("pile B\n");
    while (retemp)
    {
        ft_printf("%d\n", retemp->data);
        retemp = retemp->next;
    }
    return (0); 
}
