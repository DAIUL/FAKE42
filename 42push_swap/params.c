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