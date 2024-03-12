#include "push_swap.h"


static long ft_atol(const char *str)
{
    long    result;
    int     sign;

    result = 0;
    sign = 1;
    while (*str == 32 || *str == '\t' || *str == '\n' || \
            *str == '\r' || *str == '\f' || *str == '\v')
            str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (ft_isdigit(*str))
        result = result * 10 + (*str++ - '0');
    return (result * sign);
}

static void append_node(t_stack_node **stack, int n)
{
    t_stack_node *node;
    t_stack_node *last_node;

    if (!stack)
        return ;
    node = malloc(sizeof(t_stack_node));
    if (!node)
        return ;
    node->next = NULL;
    node->nbr = n;
    if (!(*stack))
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}

void    init_stack_a(t_stack_node **a, char **av)
{
    long    n; //store value;
    int     i;

    i = 0;
    while (av[i])
    {
        if (error_syntax(av[i]))
            free_errors(a);
        n = ft_atol(av[i]); //when str, use this ft to convert to long int
        if (n < INT_MIN || n > INT_MAX)
            free_errors(a);
        append_node(a, (int)n);
        i++;
    }
}