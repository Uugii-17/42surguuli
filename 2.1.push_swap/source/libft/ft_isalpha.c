/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:09:52 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:10:07 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	else
		return (0);
}
/*int	main(void)
{
	char	c;
	c = 'A';
	printf("\nWhen uppercase character is passed: %d", ft_isalpha(c));
	c = 'z';
	printf("\nWhen lowercase character is passed: %d", ft_isalpha(c));
	c = 1;
	printf("\nWhen non-alphabetic character is passed: %d", ft_isalpha(c));
	printf("\n");
	return(0);
}*/
