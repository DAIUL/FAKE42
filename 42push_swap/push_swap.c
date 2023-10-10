#include "push_swap.h"

t_list_ps  *ft_multiparam(char **params, t_list_ps **tab)
{
    int     i;
    t_list_ps  *temp;
    t_list_ps   *a;

    i = 0;
    if (ft_check(params, tab) == 0)
        return (ft_error(tab), NULL);
    a = ft_lstnew_ps(ft_atoi(params[i]));
    temp = a;
    while (params[i + 1])
    {
        ft_lstadd_back_ps(&a, ft_lstnew_ps(ft_atoi(params[i])));
        ft_printf("%d, ", a->data);
        a = a->next;
        i++;
    }
    a->data = ft_atoi(params[i]);
    ft_printf("%d", a->data);
    return (temp);
}

t_list_ps  *ft_soloparam(char *monoparam, t_list_ps** tab)
{
    char    **params;
    int     i;
    t_list_ps  *temp;
    t_list_ps   *a;

    i = 0;
    params = ft_split(monoparam, ' ');
    if (ft_check(params, tab) == 0)
        return (ft_printf("Error"), NULL);
    ft_printf("check2\n");
    a = ft_lstnew_ps(ft_atoi(params[i++]));
    ft_printf("check3\n");
    temp = a;
    while (params[i + 1])
    {
        ft_printf("check4\n");
        ft_lstadd_back_ps(&a, ft_lstnew_ps(ft_atoi(params[i])));
        ft_printf("%d, ", a->data);
        free(params[i]);
        a = a->next;
        i++;
    }
    a->data = ft_atoi(params[i]);
    ft_printf("%d", a->data);
    return (free(params[i]), free(params), temp);
}

int    main(int ac, char **av)
{
    t_list_ps   *a;
    //t_list_ps   *b;
    t_list_ps   **tab;

    a = NULL;
    //b = NULL;
    tab = ft_calloc(2, sizeof(t_list_ps *));
    a += 0;
    if (ac == 2)
        a = ft_soloparam(av[1], tab);
    if (ac > 2)
        a = ft_multiparam(av, tab);
    ft_printf("\n");
   // tab[0] = a;
   // tab[1] = b;
    //push_start(tab);
    //ft_printf("%d\n", opti_idc(tab));
    return (0); 
}

// le malloc du lstnew marche pas dans la giga ligne de la boucle
// le check commence a 0 donc peut etre ca marche pas pour le multiparam vu que le 0 c'est l'executable
