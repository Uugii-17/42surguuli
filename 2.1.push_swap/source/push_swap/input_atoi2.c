/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_atoi2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:54:28 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 01:08:58 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

//Here an error message is being printed out
static void	ft_error_atoi(void)
{
	write (2, "Error\n", 6);
	exit(127);
}

static void	wrong_format(t_stack **my_node)
{
	free_stack(my_node);
	ft_error_atoi();
}

static int	ft_check_int(long long int integer, t_stack **my_node, char **str)
{
	if ((integer) > 2147483647 || (integer) < -2147483648)
	{
		free_both(my_node, str);
		ft_error_atoi();
		return (2);
	}
	else
		return (0);
}

// The function check the sign of the number,
// check if it is a digit, and then transform character(s)
// to integer. In the end it checks if it's a valid integer.
int	ft_atoi2(const char *str, t_stack **my_node)
{
	int				sign;
	long long int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			wrong_format(my_node);
		result = result * 10;
		result = result + (*str - '0');
		str++;
	}
	ft_check_int(result * sign, my_node, NULL);
	return (result * sign);
}

// The function is for one string as input,
// it checks the sign of the number, checks if it is a digit,
// and then transform character(s) to integer.
// In the end it checks if it's a valid integer.
// If integer is not valid it frees stack and array of strings.
int	ft_atoi2_onearg(const char *str, t_stack **my_node, char **strings)
{
	int				sign;
	long long int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			wrong_format(my_node);
		result = result * 10;
		result = result + (*str - '0');
		str++;
	}
	ft_check_int(result * sign, my_node, strings);
	return (result * sign);
}
