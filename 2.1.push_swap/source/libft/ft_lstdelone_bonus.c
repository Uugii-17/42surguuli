/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:10:32 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:11:27 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Deletes a single node ‘lst’ from the linked list and frees its content using
the ‘del’ function, then deallocates the memory for the node. However, it fails
to remove ‘lst’ from the list fully, as it only sets the local ‘lst’ pointer
to NULL. The list re-linking must be done externally.*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
