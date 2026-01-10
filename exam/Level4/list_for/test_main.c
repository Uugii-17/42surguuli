#include <stdio.h>
#include "ft_list.h"

// Example function to apply
void    print_str(void *data)
{
    printf("%s\n", (char *)data);
}

int main(void)
{
    t_list n3 = {NULL, "42"};
    t_list n2 = {&n3, "is"};
    t_list n1 = {&n2, "Piscine"};

    ft_list_foreach(&n1, print_str);

    // Output will be:
    // Piscine
    // is
    // 42

    return 0;
}
