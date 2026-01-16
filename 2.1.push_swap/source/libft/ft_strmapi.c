/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:06:13 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/16 00:08:34 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*char	uppercase(unsigned int index, char ch)
{
	index++;
	return (ch = toupper(ch));
}
int	main(void)
{
	char str[] = "lowercase";
	char *new_str = ft_strmapi(str, uppercase);
	printf("\nOriginal:\n%s\nNew:\n%s\n", str, new_str);
}*/
