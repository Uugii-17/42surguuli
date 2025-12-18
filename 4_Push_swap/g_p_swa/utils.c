#include "push_swap.h"

void    error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

long    ft_atoi(const char *str)
{
    long    res = 0;
    int     sign = 1;
    // Full atoi with checks for overflow, non-digit
    // ...
    return (res * sign);
}

size_t  ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return (i);
}