/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:52:09 by uuenkhba          #+#    #+#             */
/*   Updated: 2025/11/25 19:18:44 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_negative(long *n)
{
	if (*n < 0)
	{
		write(1, "-", 1);
		*n = -*n;
		return (1);
	}
	return (0);
}

int	ft_print_nbr(long n)
{
	int		count;
	char	c;

	count = ft_putnbr_negative(&n);
	if (n >= 10)
		count += ft_print_nbr(n / 10);
	c = "0123456789"[n % 10];
	return (count + write(1, &c, 1));
}
