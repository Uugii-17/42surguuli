/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:09:08 by uuenkhba          #+#    #+#             */
/*   Updated: 2025/11/17 22:31:53 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int main(int ac, char **av)
{
	if(ac != 4)
	{
		printf("\n");
		return(0);
	}
	
		int num1;
		char operator;
		int num2;
		int result;
		num1 = atoi(av[1]);
		operator = av[2][0];
		num2 = atoi(av[3]);
		result = 0;
		if(operator == '+')
			result = num1 + num2;
		else if(operator == '-')
			result = num1 - num2;
		else if(operator == '*')
			result = num1 * num2;
		else if(operator == '/')
		{
			if(num2 == 0)
			{
				printf("\n");
				return(0);
			}
			result = num1 / num2;
		}
		else if(operator == '%')
		{
			if(num2 == 0)
			{
				printf("\n");
				return(0);
			}
			result = num1 % num2;
		}
		else
		{
			printf("\n");
			return (0);
		}
		printf("%d", result);
	return(0);
}
