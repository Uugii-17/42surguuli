/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:14:37 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 01:15:26 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

void	input_is_valid_onearg(char *argv, t_stack **a)
{
	int	i;

	i = 0;
	if (argv[i] == '\0')
	{
		free_stack(a);
		error_mix_exit(6);
	}
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) || argv[i] == 32)
			i++;
		else if (argv[i] == '-' && argv[i + 1] != '\0'
			&& argv[i + 1] != 32)
			i++;
		else if (argv[i] == '+' && argv[i + 1] != '\0'
			&& argv[i + 1] != 32)
			i++;
		else
		{
			free_stack(a);
			error_mix_exit(3);
		}
	}
}

void	input_is_valid(char *argv, t_stack **a)
{
	int	i;

	i = 0;
	if (argv[i] == '\0')
	{
		free_stack(a);
		error_mix_exit(6);
	}
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]))
			i++;
		else if (argv[i] == '-' && argv[i + 1] != '\0')
			i++;
		else if (argv[i] == '+' && argv[i + 1] != '\0'
			&& argv[i + 1] != 32)
			i++;
		else
		{
			free_stack(a);
			error_mix_exit(3);
		}
	}
}
