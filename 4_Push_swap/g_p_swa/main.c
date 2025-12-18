#include "push_swap.h"

// Алдаа гарвал "Error\n" хэвлээд гарах
void    error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

// Өгүүлбэрийг int болгож хувиргах (overflow, non-digit шалгадаг)
long    ft_atol(const char *str)
{
    long    result;
    int     sign;

    result = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        if (result > 2147483647 && sign == 1)
            error_exit();
        if (result > 2147483648 && sign == -1)
            error_exit();
        str++;
    }
    if (*str && (*str < '0' || *str > '9'))
        error_exit();
    return (result * sign);
}

// Давхардаж буй тоо байгаа эсэхийг шалгах
void    check_duplicates(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
                error_exit();
            j++;
        }
        i++;
    }
}

// Аргуудыг parse хийж, стек A-д хийнэ
void    parse_input(t_stacks *s, int argc, char **argv)
{
    int     i;
    int     *temp;

    s->a_size = argc - 1;
    if (s->a_size == 0)
        exit(0);
    s->a = malloc(sizeof(int) * s->a_size);
    s->b = malloc(sizeof(int) * s->a_size);
    if (!s->a || !s->b)
        error_exit();
    s->b_size = 0;

    temp = malloc(sizeof(int) * s->a_size);
    if (!temp)
        error_exit();

    i = 0;
    while (i < s->a_size)
    {
        temp[i] = (int)ft_atol(argv[i + 1]);
        s->a[i] = temp[i];
        i++;
    }
    check_duplicates(temp, s->a_size);
    free(temp);
}

// Тоонуудыг эрэмбэлэгдсэн байдлаар индекс болгож хувиргана (0 = хамгийн бага)
void    assign_indices(t_stacks *s)
{
    int     *sorted;
    int     i;
    int     j;
    int     idx;

    sorted = malloc(sizeof(int) * s->a_size);
    if (!sorted)
        error_exit();
    i = 0;
    while (i < s->a_size)
    {
        sorted[i] = s->a[i];
        i++;
    }

    // Bubble sort (n=500-д хангалттай хурдан)
    i = 0;
    while (i < s->a_size - 1)
    {
        j = 0;
        while (j < s->a_size - i - 1)
        {
            if (sorted[j] > sorted[j + 1])
            {
                int tmp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }

    // Индекс оноох
    i = 0;
    while (i < s->a_size)
    {
        j = 0;
        while (j < s->a_size)
        {
            if (s->a[i] == sorted[j])
            {
                s->a[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
    free(sorted);
}

int     main(int argc, char **argv)
{
    t_stacks    s;

    if (argc < 2)
        return (0);

    parse_input(&s, argc, argv);
    assign_indices(&s);

    // Аль хэдийн эрэмбэлэгдсэн бол юу ч хэвлэхгүй
    if (is_sorted(&s))
    {
        free(s.a);
        free(s.b);
        return (0);
    }

    // Жижиг стекүүдэд тусгай sort
    if (s.a_size <= 5)
        sort_small(&s);
    else
        radix_sort(&s);  // Том стекүүдэд radix

    free(s.a);
    free(s.b);
    return (0);
}