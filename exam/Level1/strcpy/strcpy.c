/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:42:08 by uuenkhba          #+#    #+#             */
/*   Updated: 2025/11/17 16:54:12 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char *ft_strcpy(char *s1, char *s2)
{
	int i;
	i = 0;
	while(s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return(s1);
}
int main()
{
		char *s = "Uuganaa";
		char d[50];
		printf("%s", ft_strcpy(d, s));
	return(0);
}

