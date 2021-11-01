#include "pushswap.h"

void    indexx(int **v, int **t, int *max, int min)
{
    if((*t)[(*v)[1]] < *max && (*t)[(*v)[1]] > min)
    {
        *max = (*t)[(*v)[1]];
        (*v)[2] = (*v)[1];
    }
}

int     *indexxx(int *t, int size)
{
    int *tab;
    int *v;
    int min;
    int max;

    v = malloc(sizeof(int) * 3);
    v[0] = -1;
    v[1] = 0;
    v[2] = 0;
    min = -2147483648;
    tab = malloc(sizeof(int)*size);
    while(++(v[0]) < size)
    {
        v[1] = -1;
        max = 2147483647;
        while(++(v[1]) < size)
            indexx(&v, &t, &max, min);
        tab[v[2]] = v[0];
        min = max;  
    }
    free(v);
    return(tab);
}

void    pushswap_helper(t_stack **a, t_stack **b, int i, t_op **queue)
{
    if ((((*a)->val >> i) & 1) == 1)
    {
        *a = rotate_ab(*a);
        *queue = addop(*queue, "ra");
    }
    else
    {
        ft_push_ab(a, b);
        *queue = addop(*queue, "pb");
    }
}

t_op    *pushswap(int size, t_stack *a, t_stack *b)
{
    int maxbits;
    int i;
    int j;
    t_stack *tmp;
    t_op *queue;

    queue = NULL;
    maxbits = 0;
    while ((size) >> maxbits != 0)
        maxbits++;
    i = -1;
    while (++i < maxbits)
    {
        j = -1;
        while (++j < size)
            pushswap_helper(&a, &b, i, &queue);
        while(!(b_is_empty(b)))
        {
            ft_push_ab(&b, &a);
            queue = addop(queue, "pa");
        }
    }
    return (queue);
}