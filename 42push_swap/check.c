#include "push_swap.h"

int     ft_strlen_ps(char **s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (0);
}

int     *ft_big_atoi(char **s, t_list_ps **tab)
{
    int i;
    int *params;
    long long int *check;

    i = ft_strlen_ps(s);
    params = ft_calloc((i + 1), sizeof(int));
    check = ft_calloc((i + 1), sizeof(long long int));
    i = 0;
    while (s[i])
    {
        check[i] = ft_atol(s[i]);
        i++;
    }
    i = 0;
    while (check[i])
    {
        if (check[i] > INT_MAX || check[i] < INT_MIN)
        {
            free(check);
            free(params);
            ft_error(tab);
        }
        params[i] = check[i];
        i++;
    }
    return (params);
}

int     ft_check(char **s, t_list_ps **tab)
{
    int i;
    int j;
    int *params;

    i = 0;
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
    params = ft_big_atoi(s, tab);
    i = 0;
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
    free(params);
    ft_printf("check1\n");
    return (1);
}