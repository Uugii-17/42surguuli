/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 01:13:20 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 01:14:20 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

void	error_exit(int err_number)
{
	write(2, "Error\n", 6);
	exit(err_number);
}

void	error_mix_exit(int err_number)
{
	write(2, "Error\n", 6);
	exit(err_number);
}

void	error_dup_exit(int err_number)
{
	write(2, "Error\n", 6);
	exit(err_number);
}

// Malloc error
void	error_mall_exit(int err_number)
{
	write(2, "Error\n", 6);
	exit(err_number);
}
