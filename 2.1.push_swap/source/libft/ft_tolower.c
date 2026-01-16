/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:04:54 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/15 23:05:40 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= 90 && c >= 65)
	{
		c = c - 'A' + 'a';
		return (c);
	}
	else
		return (c);
}
/*int	main(void)
{
	char	c;

	c = 'm';
	printf("%c -> %c", c, ft_tolower(c));
	c = 'D';
	printf("\n%c -> %c", c, ft_tolower(c));
	c = '9';
	printf("\n%c -> %c\n", c, ft_tolower(c));
	return (0);
}*/
