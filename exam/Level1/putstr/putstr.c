/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:25:25 by uuenkhba          #+#    #+#             */
/*   Updated: 2025/11/17 16:41:22 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void ft_putstr(char *str)
{
	int i;
	i = 0;
	while(str[i])
		write(1, &str[i++], 1);
}
int main(int ac, char **av)
{
	if(ac == 2)
	{
		ft_putstr(av[1]);
	}
	write(1, "\n", 1);
	return(0);
}
