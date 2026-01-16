/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:30:24 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:31:01 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
/*int	main(void)
{
	const char s[10] = "ABCDEFGAB";
	int c;
	char *frsoccurence;

	c = 'A';
	printf("Original string: %s\n", s);
	frsoccurence = ft_strrchr(s, c);
	printf("Pointer to the last occurence of %c is = %s\n", c, frsoccurence);
	printf("Original string: %s\n", s);
	return (0);
}*/
