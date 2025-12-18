#include "push_swap.h"

int     is_sorted(t_stacks *s)
{
    int i = 0;
    while (i < s->a_size - 1)
    {
        if (s->a[i] > s->a[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void    sort_small(t_stacks *s)
{
    // Hardcode for 2-5 elements
    if (s->a_size == 2)
    {
        if (s->a[0] > s->a[1])
            sa(s);
    }
    else if (s->a_size == 3)
    {
        // All cases for 3
        if (s->a[0] > s->a[1] && s->a[0] > s->a[2])
        {
            ra(s);
            if (s->a[0] > s->a[1])
                sa(s);
        }
        // Add other cases...
    }
    // For 4-5 similar, push to b and sort 3
}

void    radix_sort(t_stacks *s)
{
    int max_bits = 0;
    int size = s->a_size;
    int i;
    int j = 0;

    while ((size - 1) >> max_bits)
        max_bits++;
    while (j < max_bits)
    {
        i = 0;
        while (i < s->a_size)
        {
            if (((s->a[0] >> j) & 1) == 0)
                pb(s);
            else
                ra(s);
            i++;
        }
        while (s->b_size > 0)
            pa(s);
        j++;
    }
}