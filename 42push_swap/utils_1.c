#include "push_swap.h"

int     list_len(t_list_ps *a)
{
    int i;

    i = 0;
    while (a)
    {
        i++;
        a = a->next;
    }
    return (i);
}

int     last_list_data(t_list_ps *b)
{
    while (b->next)
        b = b->next;
    return (b->data);
}

int     min_max(t_list_ps *b, int idc)
{
    int limit;

    limit = 0;
    if (idc == 1)
    {
        while (b)
        {
            if (limit > b->data)
                limit = b->data;
            b = b->next;
        }
    }
    if (idc == 2)
    {
        while (b)
        {
            if (limit < b->data)
                limit = b->data;
            b = b->next;
        }
    }
    return (limit);
}

void	ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new)
{
	t_list_ps	*truc;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		truc = ft_lstlast_ps(*lst);
		truc->next = new;
	}
}

t_list_ps	*ft_lstnew_ps(int data)
{
	t_list_ps	*truc;

    ft_printf("check5\n");
	truc = malloc(sizeof(t_list_ps)); //celui la il le fait pas (crash) dans la boucle du soloparam
    ft_printf("check6\n");
	if (!truc)
		return (NULL);
	truc->data = data;
	truc->next = NULL;
	return (truc);
}