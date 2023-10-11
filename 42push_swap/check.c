#include "push_swap.h"

int     ft_strlen_ps(char **s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int     *ft_big_atoi(char **s, t_list_ps **tab, int ac)
{
    int i;
    int j;
    int *params;
    long long int *check;

    i = ft_strlen_ps(s);
    params = ft_calloc((i + 1), sizeof(int));
    check = ft_calloc((i + 1), sizeof(long long int));
    if (ac == 2)
        j = 0;
    else
        j = 1;
    i = 0;
    while (s[j])
    {
        check[i] = ft_atol(s[j]);
        i++;
        j++;
    }
    i = 0;
    if (ac == 2)
        j = 0;
    else
        j = 1;
    while (check[i])
    {
        if (check[i] > INT_MAX || check[i] < INT_MIN)
        {
            free(check);
            free(params);
            ft_error(tab);
        }
        params[i] = ft_atoi(s[j]);
        i++;
        j++;
    }
    free(check);
    return (params);
}

int     ft_double(int ac, int *params)
{
    int i;
    int j;

    if (ac == 2)
        i = 0;
    else
        i = 1;
    while (params[i])
    {
        j = i + 1;
        while (params[j])
        {
            if (params[j] == params[i])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int     ft_check(char **s, t_list_ps **tab, int ac)
{
    int i;
    int j;
    int *params;

    if (ac == 2)
        i = 0;
    else
        i = 1;
    while (s[i])
    {
        j = 0;
        while (s[i][j])
        {
            if (!(s[i][j] >= '0' && s[i][j] <= '9') || s[i][j] == '-' || s[i][j] == '+')
                return (0);
            j++;
        }
        i++;   
    }
    params = ft_big_atoi(s, tab, ac);
    if (ft_double(ac, params) == 0)
        return (0);
    free(params);
    return (1);
}