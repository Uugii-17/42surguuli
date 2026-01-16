/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:26:22 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:28:55 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*void	uppercase(unsigned int index, char *ch)
{
	index++;
	*ch = toupper(*ch);
}

int	main(void)
{
	char	str[] = "lowercase";

	ft_striteri(str, uppercase);
	printf("\n%s\n", str);
}*/
