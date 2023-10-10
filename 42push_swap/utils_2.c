#include "push_swap.h"

t_list_ps	*ft_lstlast_ps(t_list_ps *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


void    ft_error(t_list_ps **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free (tab[i]);
        i++;
    }
    ft_printf("Error\n");
    exit(EXIT_FAILURE);
}

long long int	ft_atol(const char *nptr)
{
	int	i;
	int	sign;
	long long int	vret;

	i = 0;
	sign = 1;
	vret = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		vret = vret * 10 + (nptr[i] - 48);
		i++;
	}
	return (vret * sign);
}