/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:46:26 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:52:13 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// It checks is the stack is correctly sorted in ascending order.
// is the stack is not sorted it returns 0.
int	check_sort(t_stack *stack)
{
	int	prev_nbr;

	if (!stack)
		return (0);
	prev_nbr = stack->nbr;
	stack = stack->next;
	while (stack)
	{
		if (prev_nbr > stack->nbr)
			return (0);
		prev_nbr = stack->nbr;
		stack = stack->next;
	}
	return (3);
}
