#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
    int     *a;
    int     *b;
    int     a_size;
    int     b_size;
}           t_stacks;

// operations.c
void    sa(t_stacks *s);
void    sb(t_stacks *s);
void    ss(t_stacks *s);
void    pa(t_stacks *s);
void    pb(t_stacks *s);
void    ra(t_stacks *s);
void    rb(t_stacks *s);
void    rr(t_stacks *s);
void    rra(t_stacks *s);
void    rrb(t_stacks *s);
void    rrr(t_stacks *s);

// sort.c
void    sort_small(t_stacks *s);
void    radix_sort(t_stacks *s);
int     is_sorted(t_stacks *s);

// utils.c
void    error_exit(void);
long    ft_atoi(const char *str);
void    print_op(char *op);

// push_swap.c functions (parsing, etc.)
void    parse_input(t_stacks *s, int argc, char **argv);
void    assign_indices(t_stacks *s);

#endif