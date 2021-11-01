#include "pushswap.h"

void    sort_all(int size, t_stack *a, int *tab, t_op *q)
{
    t_stack *b;

    b = NULL;
    if(size == 3)
        a = sort3(tab, size);
    else if (size == 5)
        a = sort5(a, tab, size);
    else 
    {
        q = pushswap(size, a, b);
        while (q)
        {
            printf("%s\n", q->oper);
            q = q->next;
        }
    }
}

int     main(int argc, char **argv)
{
    t_stack *a;
    t_stack *tmp;
    t_op    *q;
    int     size;
    int     *tab;

    if (argc > 1)
    {
        a = NULL;
        q = NULL;
        size = valid_parse(argv);
        tab = malloc(sizeof(int) *size);
        tab = file_tab(tab, argv);
        tab = indexxx(tab, size);
        a = fill(a, tab, size - 1);
        if (!is_sorted(a))
            sort_all(size, a, tab , q);
        system("leaks push_swap");
    }
    return (0);
}