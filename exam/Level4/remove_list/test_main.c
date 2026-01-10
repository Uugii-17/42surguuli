#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

// ─── Comparison function ────────────────────────────────────────────────
int     cmp_str(void *a, void *b)
{
    return (strcmp((char *)a, (char *)b));
}

// ─── Helper: create new node ────────────────────────────────────────────
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

// ─── Helper: print the list ─────────────────────────────────────────────
void    print_list(t_list *lst)
{
    while (lst)
    {
        printf("-> \"%s\" ", (char *)lst->data);
        lst = lst->next;
    }
    printf("\n");
}

// ─── Helper: free the entire list ───────────────────────────────────────
void    free_list(t_list **lst)
{
    t_list  *tmp;

    while (*lst)
    {
        tmp = *lst;
        *lst = (*lst)->next;
        free(tmp);
    }
}
void    ft_list_push_front(t_list **begin_list, void *data)
{
    t_list  *new_elem;

    new_elem = malloc(sizeof(t_list));
    if (new_elem == NULL)
        return ;

    new_elem->data = data;
    new_elem->next = *begin_list;     // new node points to old first node
    *begin_list = new_elem;           // head now points to new node
}
int main(void)
{
    t_list  *list = NULL;
    t_list  **begin_list = &list;

    // Create test list: "one" → "TWO" → "three" → "TWO" → "four" → "TWO"
    ft_list_push_front(begin_list, "TWO");       // will be removed
    ft_list_push_front(begin_list, "four");
    ft_list_push_front(begin_list, "TWO");       // will be removed
    ft_list_push_front(begin_list, "three");
    ft_list_push_front(begin_list, "TWO");       // will be removed
    ft_list_push_front(begin_list, "one");

    printf("Before:\n");
    print_list(list);

    // Remove all nodes containing "TWO"
    char *to_remove = "TWO";
    ft_list_remove_if(begin_list, to_remove, cmp_str);

    printf("\nAfter removing all \"TWO\":\n");
    print_list(list);

    // Another test: remove something that doesn't exist
    printf("\nTrying to remove \"xyz\" (not present):\n");
    ft_list_remove_if(begin_list, "xyz", cmp_str);
    print_list(list);

    // Clean up
    free_list(begin_list);

    return (0);
}
/*// Empty list
t_list *empty = NULL;
ft_list_remove_if(&empty, "anything", cmp_str);     // should not crash

// Only one element - to be removed
t_list *single = ft_create_elem("delete");
ft_list_remove_if(&single, "delete", cmp_str);      // should become NULL

// All elements to be removed
t_list *all_same = NULL;
ft_list_push_front(&all_same, "hi");
ft_list_push_front(&all_same, "hi");
ft_list_push_front(&all_same, "hi");
ft_list_remove_if(&all_same, "hi", cmp_str);        // should become NULL*/
