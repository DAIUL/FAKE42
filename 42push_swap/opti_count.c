#include "push_swap.c"

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

int     a_min_steps(t_list_ps *a, int nb)
{
    int i;
    int size;

    i = 1;
    size = list_len(a);
    while (nb != a->data)
    {
        i++;
        a = a->next;
    }
    if (i > (size/2))
        return (size - (i - 1));
    else
        return (i - 1);
}

int     b_min_steps(t_list_ps *b, int nb)
{
    int i;
    int size;

    i = 1;
    size = list_len(b);
    // CASE IF NB IS MORE THAN MAX OR LES THAN MIN
    if (nb > b->data && nb < last_list_data(b))
        return (i);
    while (!(nb > b->next->data && nb < a->data))
    {
        i++;
        b = b->next;
    }
    if (i > (size/2))
        return (size - i);
    else
        return (i);
}