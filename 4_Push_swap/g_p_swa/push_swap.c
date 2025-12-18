#include "push_swap.h"

void    parse_input(t_stacks *s, int argc, char **argv)
{
    int     i;
    int     j;
    char    **args;
    // Simple parsing (supports quoted args too, but for simplicity assume separate args)
    // Full parsing with ft_split if needed, but here direct
    s->a_size = argc - 1;
    s->a = malloc(sizeof(int) * s->a_size);
    s->b = malloc(sizeof(int) * s->a_size);
    if (!s->a || !s->b)
        error_exit();
    s->b_size = 0;
    i = 0;
    while (++i < argc)
    {
        s->a[i - 1] = ft_atoi(argv[i]);
        // Duplicate and range check can be added here
    }
    assign_indices(s);  // Normalize to 0..n-1
}

void    assign_indices(t_stacks *s)
{
    int     *sorted;
    int     i;
    int     j;

    sorted = malloc(sizeof(int) * s->a_size);
    if (!sorted)
        error_exit();
    i = -1;
    while (++i < s->a_size)
        sorted[i] = s->a[i];
    // Simple bubble sort for indices (n=500 ok)
    i = -1;
    while (++i < s->a_size - 1)
    {
        j = -1;
        while (++j < s->a_size - i - 1)
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
    }
    i = -1;
    while (++i < s->a_size)
    {
        j = -1;
        while (++j < s->a_size)
            if (s->a[i] == sorted[j])
                s->a[i] = j;
    }
    free(sorted);
}

int     main(int argc, char **argv)
{
    t_stacks    s;

    if (argc < 2)
        return (0);
    parse_input(&s, argc, argv);
    if (is_sorted(&s))
        return (0);
    if (s.a_size <= 5)
        sort_small(&s);
    else
        radix_sort(&s);
    free(s.a);
    free(s.b);
    return (0);
}