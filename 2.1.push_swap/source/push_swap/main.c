/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:15:58 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 01:16:18 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc == 1)
		exit(1);
	if (argc == 2)
		a = one_arg(argv);
	else
		a = input_into_stack(argc, argv);
	if (!a || dup_search(a))
	{
		free_stack(&a);
		error_dup_exit(4);
	}
	if (!check_sort(a))
	{
		if (ft_lstsize(a) == 2)
			ft_sa(&a);
		else
			sort_algorithm(&a);
	}
	free_stack(&a);
	return (0);
}
