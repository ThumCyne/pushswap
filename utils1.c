#include "pushswap.h"


int     b_is_empty(t_stack *b)
{
    if(!b)
        return (1);
    return (0);
}

void       ft_push_ab(t_stack **a, t_stack **b)
{
    t_stack *mem;
    int value;
    if(a)
    {
        value = (*a)->val;
        *b = ft_push(*b, value);
        *a = (*a)->next;
    }
}


t_stack     *rotate_ab(t_stack *p)
{
    t_stack *tmp;
    t_stack *new;
    int     val;

    val = p->val;
    p = p->next;

    tmp = p;
    new = (t_stack*)malloc(sizeof(t_stack));
    if(new)
    {
        new->next = NULL;
        new->val = val;
        while (p->next)
        {
            p = p->next;
        }
        p->next = new;
    }
    return (tmp);
}

t_stack     *ft_push(t_stack *pile, int data)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if(new)
    {
        new->val = data;
        new->next = pile;
        return (new);
    }
    return (NULL);
}


t_op        *addop(t_op *queue, char *str)
{
    t_op    *new;
    t_op    *tmp;

    new = (t_op*)malloc(sizeof(t_op));
    if (new)
    {
        new->next = NULL;
        new->oper = str;
        if(queue == NULL)
            return(new);
        else
        {
            tmp = queue;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = new;
        }
    }
    return(queue);
}