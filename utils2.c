#include "pushswap.h"

int     *file_tab(int *t, char **av)
{
    int i;

    i = 1;
    while(av[i])
    {
        t[i-1] = atoi(av[i]);
        i++;
    }
    return (t);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i += 1;
    }
}

int     is_digit(char *str)
{
    int i;

    i = 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    while(str[i])
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
        {
            ft_putstr("INVALID ARGUMENTS\n");
            exit(1);
        }
        i++;
    }
    return (1);
}

int     valid_parse(char **str)
{
    int i;

    i = 1;
    while(str[i] && is_digit(str[i]))
        i++;
    return (i - 1);
}