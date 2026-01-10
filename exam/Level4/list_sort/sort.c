#include <stddef.h>
#include "list.h"
t_list  *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list 	*current;
    t_list	*next;
    int     swapped;

    if (lst == NULL)
        return (NULL);

    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        current = lst;

        while (current->next != NULL)
        {
		next = current->next;
            // If cmp returns 0 → elements are in WRONG order → swap
            if ((*cmp)(current->data, next->data) == 0)
            {
                int tmp = current->data;
                current->data = next->data;
                next->data = tmp;
                swapped = 1;
            }
            current = current->next;
        }
    }

    return (lst);
}
t_list *ft_create_elem(int data);
void   ft_list_push_back(t_list **begin, int data);  // or use push_front
t_list  *ft_create_elem(void *data)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->data = data;
    new->next = NULL;
    return (new);
}

void    ft_list_push_back(t_list **begin_list, void *data)
{
    t_list  *new;
    t_list  *current;

    new = ft_create_elem(data);
    if (!new)
        return ;

    // Empty list case
    if (*begin_list == NULL)
    {
        *begin_list = new;
        return ;
    }

    // Find the last element
    current = *begin_list;
    while (current->next != NULL)
        current = current->next;

    current->next = new;
}
int ascending(int a, int b) { return (a <= b); }
int descending(int a, int b) { return (a >= b); }

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d → ", lst->data);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(void)
{
    t_list *list = NULL;

    ft_list_push_back(&list, 42);
    ft_list_push_back(&list, 7);
    ft_list_push_back(&list, 19);
    ft_list_push_back(&list, -3);
    ft_list_push_back(&list, 88);
    ft_list_push_back(&list, 7);

    printf("Before sort:\n");
    print_list(list);

    list = sort_list(list, ascending);
    printf("\nAfter ascending sort:\n");
    print_list(list);

    list = sort_list(list, descending);
    printf("\nAfter descending sort:\n");
    print_list(list);
    free(list);
    // Don't forget to free the list in real tests...
    return (0);
}
