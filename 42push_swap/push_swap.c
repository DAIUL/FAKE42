#include "push_swap.h"

t_list_ps  *ft_multiparam(char **params)
{
    int     i;
    t_list_ps  *temp;
    t_list_ps   *a;

    i = 0;
    ft_check(params);
    a = ft_calloc(1, sizeof(t_list_ps *));
    temp = a;
    while (params[i + 1])
    {
        a->next = ft_calloc(1, sizeof(t_list_ps *));
        a->data = ft_atoi(params[i]);
        ft_printf("%s, ", a->data);
        a = a->next;
        i++;
    }
    a->data = ft_atoi(params[i]);
    ft_printf("%s", a->data);
    return (temp);
}

t_list_ps  *ft_soloparam(char *monoparam)
{
    char    **params;
    int     i;
    t_list_ps  *temp;
    t_list_ps   *a;

    i = 0;
    params = ft_split(monoparam, ' ');
    ft_check(params);
    a = ft_calloc(1, sizeof(t_list_ps *));
    temp = a;
    while (params[i + 1])
    {
        a->next = ft_calloc(1, sizeof(t_list_ps *));
        a->data = ft_atoi(params[i]);
        ft_printf("%s, ", a->data);
        free(params[i]);
        a = a->next;
        i++;
    }
    a->data = ft_atoi(params[i]);
    ft_printf("%s", a->data);
    return (free(params[i]), free(params), temp);
}

int    main(int ac, char **av)
{
    t_list_ps   *a;

    a = NULL;
    a += 0;
    if (ac == 2)
        a = ft_soloparam(av[1]);
    if (ac > 2)
        a = ft_multiparam(av);
    ft_printf("\n");
    return (0); 
}