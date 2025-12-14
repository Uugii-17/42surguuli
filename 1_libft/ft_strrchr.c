/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:35:53 by uuenkhba          #+#    #+#             */
/*   Updated: 2025/10/21 20:27:18 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*pch;

	pch = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			pch = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		pch = (char *)&s[i];
	return (pch);
}
