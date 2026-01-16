/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:51:24 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/15 22:53:03 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	lensrc;
	size_t	lendst;
	size_t	total_len;
	size_t	i;
	size_t	j;

	i = 0;
	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	j = lendst;
	if (n > lendst)
		total_len = lendst + lensrc;
	else
		total_len = lensrc + n;
	while (src[i] && j + 1 < n)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (total_len);
}
