char *ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while(s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return(s1);
}
#include <stdio.h>
int main()
{
	char *s2 = "uuganaa";
	char s1[10]; 
	printf("%s\n", s2);
	ft_strcpy(s1, s2);
	printf("%s", s1);
}
