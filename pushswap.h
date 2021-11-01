#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

typedef struct s_stack
{
    int val;
    struct  s_stack *next;
}   t_stack;

typedef struct s_op
{
    char    *oper;
    struct  s_op *next;
}   t_op;

t_stack    *sort3(int *tab, int size);
int is_max(t_stack *a);
t_stack     *reverse_rotate(t_stack *a);
int     is_sorted(t_stack *a);
t_stack     *fill(t_stack *a, int *tab, int size);
t_stack    *sort5(t_stack *a, int *tab, int size);
t_op        *addop(t_op *queue, char *str);
t_stack     *ft_push(t_stack *pile, int data);
t_stack     *rotate_ab(t_stack *p);
void       ft_push_ab(t_stack **a, t_stack **b);
int     b_is_empty(t_stack *b);
int     valid_parse(char **str);
int     is_digit(char *str);
void    ft_putstr(char *str);
void    ft_putchar(char c);
int     *file_tab(int *t, char **av);
t_op    *pushswap(int size, t_stack *a, t_stack *b);
int     *indexxx(int *t, int size);

#endif