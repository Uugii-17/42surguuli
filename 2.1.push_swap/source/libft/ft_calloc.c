/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:06:11 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/15 23:08:52 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr != 0)
		ft_bzero(ptr, count * size);
	return (ptr);
}
/*int	main(void)
{
	int	*p;

	p = ft_calloc(10, sizeof(int));
	for (int i = 0; i < 10; i++)
		p[i] = i * 5;
	for (int i = 0; i < 10; i++)
		printf("%d\n", p[i]);
	return (0);
}*/
