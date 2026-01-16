/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:31:32 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:31:55 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (16384);
	else
		return (0);
}
/*int	main(void)
{
	char	c;

	c = 'S';
	printf("\nResult when a printable character %c is passed to isprint(): %d",
		c, ft_isprint(c));
	c = '\n';
	printf("\nResult when a control character is passed to isprint(): %d\n",
		ft_isprint(c));
	return (0);
}*/
