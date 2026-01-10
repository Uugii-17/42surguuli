#include <stdlib.h>
static int is_separator(char c)
{
	return(c == ' ' || c == '\t' || c == '\n');
}
static int count_words(char *str)
{
	int count = 0;
	int i = 0;
	while(str[i])
	{
		while(str[i] && is_separator(str[i]))
			i++;
		if(str[i])
		{
			count++;
			while(str[i] && !is_separator(str[i]))
				i++;
		}
	}
	return(count);
}
static char *saved_word(char *str, int start, int len)
{
	char *word;
	int i;
	word = malloc(sizeof(char) * (len + 1));
	if(!word)
		return NULL;
	i = 0;
	while(i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
char **ft_split(char *str)
{
	char **res;
	int words_count;
	int i;
	int j;
	int start;
	if(!str)
		return(NULL);
	words_count = count_words(str);
	res = malloc(sizeof(char*) * (words_count +1));
	if(!res)
		return(NULL);
	i = 0;
	j = 0;
	while(str[i] && j < words_count)
	{
		while(str[i] && is_separator(str[i]))
			i++;
		start = i;
		while(str[i] && !is_separator(str[i]))
			i++;
		if(i > start)
		{
			res[j] = saved_word(str, start, i - start);
			if(!res[j])
			{
				while(j > 0)
					free(res[--j]);
				free(res);
				return (NULL);
			}
			j++;
		}
	}
	res[j] = NULL;
	return(res);
}
int main(void)
{
	char **res = ft_split("a b");
	int i = 0;
	while(res && res[i])
		printf("%s\n", res[i++]);
	return(0);
}
