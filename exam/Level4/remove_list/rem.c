#include "ft_list.h"
#include <stdlib.h>

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *curr;
    t_list  *to_delete;

    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        to_delete = *begin_list;
        *begin_list = (*begin_list)->next;
        free(to_delete);
    }

    curr = *begin_list;
    while (curr && curr->next)
    {
        if (cmp(curr->next->data, data_ref) == 0)
        {
            to_delete = curr->next;
            curr->next = curr->next->next;
            free(to_delete);
        }
        else
            curr = curr->next;
    }
}
