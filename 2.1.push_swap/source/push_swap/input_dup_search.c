/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_dup_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:44:33 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:45:07 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// It checks if there are duplicates on the stack.
int	dup_search(t_stack *a)
{
	t_stack	*compare;

	if (!a)
		return (1);
	compare = a->next;
	while (a->next != NULL)
	{
		while (compare != NULL)
		{
			if (compare->nbr == a->nbr)
				return (1);
			compare = compare->next;
		}
		a = a->next;
		compare = a->next;
	}
	return (0);
}
