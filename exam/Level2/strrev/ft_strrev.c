char *ft_strrev(char *str)
{
	int i;
	int len;
	char tmp;
	i = 0;
	len = 0;
	while(str[len] != '\0')
		len++;
	while(i < len - 1)
	{
		tmp = str[i];
		str[i] = str[len -1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
	return(str);
}
#include <stdio.h>
int main()
{
	char s1[] = "Uuganaa";
    printf("%s -> %s\n", "Uuganaa", ft_strrev(s1));
}
