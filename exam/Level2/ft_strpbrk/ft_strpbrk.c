#include <stddef.h>
/*char *ft_strpbrk(const char *s1, const char *s2)
{
	int i;
	int j;
	i = 0;
	while(s1[i] != '\0')
	{
		j = 0;
		while(s2[j] != '\0')
		{
			if(s1[i] == s2[j])
				return((char*)&s1[i]);
			j++;
		}
		i++;
	}
	return NULL;
}*/
char *ft_strpbrk(const char *s1, const char *s2)
{
	if(!s1 || !s2)
		return NULL;
	while(*s1)
	{
		const char *p = s2;
		while(*p)
		{
			if(*s1 == *p)
				return((char*)s1);
			p++;
		}
		s1++;
	}
	return NULL;
}   
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("%s\n", ft_strpbrk("hello world", "aeiou"));     // "ello world"
    printf("%s\n", strpbrk("hello world", "aeiou"));        // "ello world"

    printf("%s\n", ft_strpbrk("hello", "xyz"));              // (null)
    printf("%p\n", (void *)ft_strpbrk("hello", "xyz"));     // (nil)

    printf("%s\n", ft_strpbrk("test", "s"));                 // "st"
    printf("%s\n", ft_strpbrk("", "abc"));                  // (null)
    printf("%s\n", ft_strpbrk("abc", ""));                  // (null)

    return (0);
}
/*#include <stdio.h>
int main(int ac, char **av)
{
	if(ac == 3)
	{
		printf("%s\n", ft_strpbrk(av[1], av[2]));
	}
	printf("\n");
	return(0);
}*/
