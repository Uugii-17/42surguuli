/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:59:19 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/15 23:01:00 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*strtoreturn;

	strtoreturn = (unsigned char *) s;
	i = 0;
	while (n > i)
	{
		if (strtoreturn[i] == (unsigned char)c)
			return ((void *) &strtoreturn[i]);
		i++;
	}
	return (NULL);
}
/*int	main(void)
{
	const char	s[10] = "DCBABCDA";
	const char	s2[10] = "DCBDCBBCD";
	int			c;
	size_t		n;
	char		*new;
	char		*newnew;

	c = 'A';
	n = 5;
	printf("Original string #1: %s\nOriginal string #2: %s\n", s, s2);
	new = (void *)ft_memchr(s, c, n);
	return (0);
}*/
