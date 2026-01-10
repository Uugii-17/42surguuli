#include <stddef.h>
size_t ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t j;
	i = 0;
	while(s[i] != '\0')
	{
		j = 0;
		while(reject[j] != '\0')
		{
			if(s[i]== reject[j])
				return(i);
			j++;
		}
		i++;
	}
	return(i);
}
#include <stdio.h>
#include <string.h>
int main(void)
{
    // Test cases to compare ft_strcspn with the real strcspn

    const char *str1 = "Hello world";
    const char *reject1 = "aeiou";
    printf("Test 1:\n");
    printf("expected: %zu\n", strcspn(str1, reject1));
    printf("yours   : %zu\n\n", ft_strcspn(str1, reject1));

    const char *str2 = "abcdef";
    const char *reject2 = "xyz";
    printf("Test 2 (no reject chars):\n");
    printf("expected: %zu\n", strcspn(str2, reject2));
    printf("yours   : %zu\n\n", ft_strcspn(str2, reject2));

    const char *str3 = "12345";
    const char *reject3 = "5";
    printf("Test 3:\n");
    printf("expected: %zu\n", strcspn(str3, reject3));
    printf("yours   : %zu\n\n", ft_strcspn(str3, reject3));

    const char *str4 = "";
    const char *reject4 = "abc";
    printf("Test 4 (empty string):\n");
    printf("expected: %zu\n", strcspn(str4, reject4));
    printf("yours   : %zu\n\n", ft_strcspn(str4, reject4));

    const char *str5 = "no match here";
    const char *reject5 = "";
    printf("Test 5 (empty reject):\n");
    printf("expected: %zu\n", strcspn(str5, reject5));
    printf("yours   : %zu\n\n", ft_strcspn(str5, reject5));

    const char *str6 = "abc\0hidden";
    const char *reject6 = "c";
    printf("Test 6 (with null in middle):\n");
    printf("expected: %zu\n", strcspn(str6, reject6));
    printf("yours   : %zu\n\n", ft_strcspn(str6, reject6));

    return (0);
}
	/*/	if(ac == 3)
	{
		printf("%ld\n", ft_strcspn(av[1], av[2]));
	}
	return(0);
	*/

