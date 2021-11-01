#include "pushswap.h"

void    sort3_helper_1(int **tab, int tmp)
{
    if((*tab)[0] < (*tab)[1] && (*tab)[0]
        > (*tab)[2] && (*tab)[1] > (*tab)[2])
    {
        printf("rra\n");
        tmp = (*tab)[2];
        (*tab)[2] = (*tab)[1];
        (*tab)[1] = (*tab)[0];
        (*tab)[0] = tmp;
    }
}

void    sort3_helper(int **tab, int tmp)
{
    if((*tab)[0] > (*tab)[1] && (*tab)[0]
        > (*tab)[2] && (*tab)[1] < (*tab)[2])
    {
        printf("ra\n");
        tmp = (*tab)[0];
        (*tab)[0] = (*tab)[1];
        (*tab)[1] = (*tab)[2];
        (*tab)[2] = tmp;

    }
    else if((*tab)[0] < (*tab)[1] && (*tab)[0]
        < (*tab)[2] && (*tab)[1] > (*tab)[2])
    {
        printf("sa\nra\n");
        tmp = (*tab)[1];
        (*tab)[1] = (*tab)[2];
        (*tab)[2] = tmp;
    }
    else
        sort3_helper_1(tab, tmp);
}

t_stack    *sort3(int *tab, int size)
{
    int tmp;
    t_stack *a;
    a = NULL;

    if(tab[0] > tab[1] && tab[0] < tab[2] && tab[1] < tab[2])
    {
        printf("sa\n");
        tmp = tab[0];
        tab[0] = tab[1];
        tab[1] = tmp;
    }
    else if(tab[0] > tab[1] && tab[0] > tab[2] && tab[1] > tab[2])
    {
        printf("sa\nrra\n");
        tmp = tab[2];
        tab[2] = tab[0];
        tab[0] = tmp;
        
    }
    else 
        sort3_helper(&tab, tmp);
    a = fill(a, tab, size - 1);
    return (a);
}