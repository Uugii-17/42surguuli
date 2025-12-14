/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:11:51 by uuenkhba          #+#    #+#             */
/*   Updated: 2025/10/21 23:39:17 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*get_word(char const *s, char c, int *pos)
{
	int		start;
	int		len;
	int		i;
	char	*word;

	start = *pos;
	len = 0;
	i = 0;
	while (s[*pos] && s[*pos] != c)
	{
		(*pos)++;
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	ft_free(char **result, int i)
{
	while (i-- > 0)
		free(result[i]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		pos;

	pos = 0;
	i = 0;
	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result | !s)
		return (NULL);
	while (i < words)
	{
		while (s[pos] == c)
			pos++;
		result[i] = get_word(s, c, &pos);
		if (!result[i])
		{
			ft_free(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
