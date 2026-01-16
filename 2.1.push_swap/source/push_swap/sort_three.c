/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:17:24 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 01:17:53 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Sorting three element of stack 'a' in ascending order.
void	sort_three(t_stack **stack_a)
{
	if (min_nbr(*stack_a) == (*stack_a)->nbr)
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
	else if (max_nbr(*stack_a) == (*stack_a)->nbr)
	{
		ft_ra(stack_a);
		if (!check_sort(*stack_a))
			ft_sa(stack_a);
	}
	else
	{
		if (cur_place(*stack_a, max_nbr(*stack_a)) == 1)
			ft_rra(stack_a);
		else
			ft_sa(stack_a);
	}
}
