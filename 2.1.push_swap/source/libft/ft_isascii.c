/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:16:26 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:16:42 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*int	main(void)
{
	int c;
	c = 'A';
	printf("\n%d - if it is a alphanumerical ASCII character", ft_isascii(c));

	c = 0x80;
	printf("\n%d - if it is not an ASCII character", ft_isascii(c));

	c = 127;
	printf("\n%d - if it is a non-alphanumerical ASCII character\n",
		ft_isascii(c));
	return (0);
}*/
