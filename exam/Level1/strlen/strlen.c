/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:54:55 by uuenkhba          #+#    #+#             */
/*   Updated: 2025/11/17 16:57:49 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_strlen(char *str)
{
	int i;
	i = 0;
	while(str[i])
		i++;
	return(i);
}
int main(int ac, char **av)
{
	if(ac == 2)
	{
		printf("%d\n", ft_strlen(av[1]));
	}
	return (0);
}
