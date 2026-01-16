/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:17:06 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:17:47 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Iterates through a linked list ‘lst’ and applies the function ‘f’ to each
node’s content. If ‘lst’ or ‘f’ is NULL, the function returns. The loop runs
while there are still nodes in the list. Within each iteration, the ‘f’ function
is called with the content of the current node, and the ‘lst’ pointer is moved
to the next node in the list.*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
