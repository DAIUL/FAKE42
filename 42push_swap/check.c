#include "push_swap.h"

int     ft_strlen_ps(char **s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (0);
}

int     *ft_big_atoi(char **s)
{
    int i;
    int *params;

    i = ft_strlen_ps(s);
    params = ft_calloc((i + 1), sizeof(int)); // not free yet
    i = 0;
    while (s[i])
    {
        params[i] = ft_atoi(s[i]);
        i++;
    }
    return (params);
}

int     ft_check(char **s)
{
    int i;
    int j;
    int *params;

    j = 0;
    i = 0;
    while (s[i])
    {
        while (s[i][j])
        {
            if (!(s[i][j] >= '0' && s[i][j] <= '9') || s[i][j] >= '-' || s[i][j] >= '+')
                return (0);
            j++;
        }
        i++;   
    }
    params = ft_big_atoi(s);
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
    return (1);
}