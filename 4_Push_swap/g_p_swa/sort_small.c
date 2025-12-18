void    sort_small(t_stacks *s)
{
    if (is_sorted(s))
        return ;
    if (s->a_size == 2)
    {
        if (s->a[0] > s->a[1])
            sa(s);
    }
    else if (s->a_size == 3)
        sort_three(s);
    else
    {
        // 4 эсвэл 5-д: pb хийж 3 болгоно
        while (s->a_size > 3)
            pb(s);
        sort_three(s);
        while (s->b_size)
            pa(s);
        // Эцэст хамгийн бага (0) дээр байх ёстой
        int pos = 0;
        while (s->a[pos] != 0)
            pos++;
        while (pos--)
            ra(s);
        // Эсвэл хямд rotate (ra vs rra) сонгох
    }
}