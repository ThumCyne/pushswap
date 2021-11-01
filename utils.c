#include "pushswap.h"

t_stack     *fill(t_stack *a, int *tab, int size)
{
    int i;
    t_stack *tmp;

    i = 0;
    //printf("size %d\n", size);
    while (i <= size)
    {
        a = ft_push(a, tab[size]);
        size--;
    }
    return (a);
}


int     is_sorted(t_stack *a)
{   int i;

    i = 0;
    while (a)
    {
        if (a->val != i)
            return (0);
        i++;
        a = a->next;
    }
    return (1);
}

int is_max(t_stack *a)
{   
    t_stack *tmp;

    int max;
    max = a->val;
    tmp = a->next;
    while (tmp)
    {
        if (tmp->val > max)
            return (0);
        tmp = tmp->next;
    }
    return (0);
}


t_stack     *reverse_rotate(t_stack *a)
{
    t_stack *new;
    t_stack *tmp;

    tmp = a;
    new = (t_stack *)malloc(sizeof(t_stack));
    while (tmp->next->next)
        tmp = tmp->next;
    new->val = tmp->next->val;
    new->next = a;
    tmp->next = NULL; 
    return (new);
}