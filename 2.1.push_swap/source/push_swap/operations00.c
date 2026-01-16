/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:45:36 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:45:57 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

void	ft_sa(t_stack **a)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "sa\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	write(1, "pa\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1, "ss\n", 3);
}

// Shifts all the elements of the stack 'a' up by one position.
// The first element becomes the last. 
void	ft_ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*help;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	help = ft_lstlast(*a);
	help->next = tmp;
	help = tmp->next;
	tmp->next = NULL;
	*a = help;
	write(1, "ra\n", 3);
}
