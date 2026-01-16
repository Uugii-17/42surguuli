/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:11:52 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:13:19 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destmov;
	char	*srcmov;
	size_t	i;

	if (!dest && !src)
		return (dest);
	destmov = (char *)dest;
	srcmov = (char *)src;
	i = 0;
	if (destmov > srcmov)
		while (n--)
			destmov[n] = srcmov[n];
	else
	{
		while (n--)
		{
			destmov[i] = srcmov[i];
			i++;
		}
	}
	return (destmov);
}
/*int	main(void)
{
	char	dest[7] = "BERLIN";
	char	*src;
	char	d[10] = "Richtig";
	char	s[10] = "Falsch";

	src = dest;
	printf("Overlapping\nDestination: %s, Source: %s\n", dest, src);
	ft_memmove(dest + 1, src, 5);
	printf("After ft_memmove\nDestination: %s, Source: %s\n", dest, src);
	printf("Without overlapping\nDestination: %s, Source: %s\n", d, s);
	ft_memmove(d, s, 6);
	printf("After ft_memmove\nDestination: %s, Source: %s\n", d, s);
	return (0);
}*/
