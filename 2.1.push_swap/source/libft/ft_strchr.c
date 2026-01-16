/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:04:39 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:05:53 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locate first occurence of the character in a string.
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	else
		return (0);
}
/*int	main(void)
{
	const char s[10] = "ABCDEFGAB";
	int c;
	char *frsoccurence;

	c = 'A';
	printf("Original string: %s\n", s);
	frsoccurence = ft_strchr(s, c);
	printf("Pointer to the first occurence of %c is = %s\n", c, frsoccurence);
	printf("Original string: %s\n", s);
	return (0);
}*/
