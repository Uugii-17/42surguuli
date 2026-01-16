/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:01:22 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:02:41 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Clears the entire linked list pointed to by ‘lst’ and deallocates memory
for each node. The ‘del’ function is used to free the memory associated with
the content of each node. If ‘lst’ is NULL, ‘del’ is NULL, or the list is
already empty, the function returns. The function recursively calls itself with
the next node until the end of the list is reached. Then, it frees the content
of the current node, deallocates the node itself, and sets ‘lst’ to NULL.*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
