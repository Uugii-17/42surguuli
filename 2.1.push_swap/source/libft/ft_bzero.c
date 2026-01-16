/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:56:14 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/15 22:57:06 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*int	main(void)
{
	unsigned char	str[17] = "Hitchhiker";
	size_t			n;

	n = 3;
	printf("%s\n", str);
	ft_bzero(str + 7, n);
	printf("%s\n", str);
	return (0);
}*/
