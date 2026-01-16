/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:10:20 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/15 23:10:25 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const unsigned char	*cs1;
	const unsigned char	*cs2;

	cs1 = s1;
	cs2 = s2;
	i = 0;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}
/*int	main(void)
{
	char str1[15] = "ABCDEf";
	char str2[15] = "ABCDEF";
	int ret;

	ret = ft_memcmp(str1, str2, 6);
	if (ret > 0)
	{
		printf("str2 is less than str1\n");
	}
	else if (ret < 0)
	{
		printf("str1 is less than str2\n");
	}
	else
	{
		printf("str1 is equal to str2\n");
	}
	return (0);
}*/
