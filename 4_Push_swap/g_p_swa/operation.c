#include "push_swap.h"

void    print_op(char *op)
{
    write(1, op, ft_strlen(op));
    write(1, "\n", 1);
}

void    sa(t_stacks *s) { if (s->a_size > 1) { int temp = s->a[0]; s->a[0] = s->a[1]; s->a[1] = temp; } print_op("sa"); }
void    sb(t_stacks *s) { if (s->b_size > 1) { int temp = s->b[0]; s->b[0] = s->b[1]; s->b[1] = temp; } print_op("sb"); }
void    ss(t_stacks *s) { sa(s); sb(s); }  // No print twice
// Adjust print for ss etc if needed

void    pa(t_stacks *s)
{
    if (s->b_size > 0)
    {
        int i = s->a_size++;
        while (i > 0)
        {
            s->a[i] = s->a[i - 1];
            i--;
        }
        s->a[0] = s->b[0];
        i = 0;
        while (++i < s->b_size)
            s->b[i - 1] = s->b[i];
        s->b_size--;
    }
    print_op("pa");
}

// pb, ra, rra гэх мэт адилхан (массив shift)

void    pb(t_stacks *s)
{
    if (s->a_size > 0)
    {
        int i = s->b_size++;
        while (i > 0)
        {
            s->b[i] = s->b[i - 1];
            i--;
        }
        s->b[0] = s->a[0];
        i = 0;
        while (++i < s->a_size)
            s->a[i - 1] = s->a[i];
        s->a_size--;
    }
    print_op("pb");
}

void    ra(t_stacks *s)
{
    if (s->a_size > 1)
    {
        int temp = s->a[0];
        int i = 0;
        while (++i < s->a_size)
            s->a[i - 1] = s->a[i];
        s->a[s->a_size - 1] = temp;
    }
    print_op("ra");
}

// rb, rr, rra, rrb, rrr адилхан бичих