#include <stdlib.h>
char *ft_strdup(char *src)
{
	int i;
	int len;
	char *dup;
	len = 0;
	while(src[len])
		len++;
	dup = (char*)malloc(sizeof(char) * (len + 1));
	if(!dup)
		return NULL;
	i = 0;
	while(src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return(dup);
}
#include <stdio.h>
int main()
{
	char *src = "Uugana";
	char *dup;
	printf("src = %s\n", src);
	dup = ft_strdup(src);
	printf("dup = %s\n", dup);
	free(dup);
	return(0);
}
