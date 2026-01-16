/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:18:17 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:19:07 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*strptr;
	size_t			i;

	i = 0;
	strptr = s;
	while (i < n)
	{
		strptr[i] = c;
		i++;
	}
	return (s);
}
/*int	main(void)
{
	char	str[20] = "Hitchhiker's guide";
	char	c;
	size_t	n;

	c = '#';
	n = 5;
	printf("Before ft_memset: %s\n", str);
	ft_memset(str, c, n);
	printf("After ft_memset:  %s\n", str);
	return (0);
}*/
