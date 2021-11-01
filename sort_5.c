#include "pushswap.h"

int is_min(t_stack *a)
{   
    t_stack *tmp;

    int min;
    min = a->val;
    tmp = a->next;
    while (tmp)
    {
        if (tmp->val < min)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void       rev_or_rot(t_stack **a, int j)
{
    if (j > 2)
    {
        printf("rra\n");
        *a = reverse_rotate(*a);
    }
    else
    {
        printf("ra\n");
        *a = rotate_ab(*a);
    }
}

int    count_j(t_stack *a, int value)
{
    t_stack *tmp;
    int     j;

    j = 0;
    tmp = a;
    while (tmp)
    {
        if (tmp->val == value)
            break;
        j++;
        tmp = tmp->next;
    }
    return (j);
}

void        sort5_helper(t_stack **a, t_stack **b, int j)
{
    if (is_min(*a) && ((*b)->val == 4))
    {
        ft_push_ab(b, a);
        printf("pa\n");
    }
    else if ((*b)->val == (*a)->val - 1)
    {
        ft_push_ab(b, a);
        printf("pa\n");
    }
    else
    {
        if ((*b)->val <= 3)
        {
            j = count_j(*a, (*b)->val + 1);
            rev_or_rot(a, j);
        }
        else
        {
            printf("ra\n");
            *a = rotate_ab(*a);
        }
    }
}

t_stack    *sort5(t_stack *a, int *tab, int size)
{
    t_stack *b;
    int j;

    j = 0;
    b = NULL;
    b = ft_push(b, tab[0]);
    b = ft_push(b, tab[1]);
    printf("pb\npb\n");
    a = sort3(tab + 2, 3);
    if (b->val < b->next->val)
    {
        printf("rb\n");
        b = rotate_ab(b);
    }
    while (b)
        sort5_helper(&a, &b, j);
    j = count_j(a, 0);
    while (is_sorted(a) == 0)
        rev_or_rot(&a, j);
    return (a);
}