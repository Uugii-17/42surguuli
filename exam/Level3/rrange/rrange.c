#include <stdlib.h>
int *ft_rrange(int start, int end)
{
	int size = 0;
	int i = 0;
	int *tab;
	if(start <= end)
		size = end - start + 1;
	else
		size = start - end + 1;
	tab = malloc(sizeof(int) * size);
	if(!tab)
		return(0);
	while(i < size)
	{
		tab[i] = end;
		if(end < start)
			end++;
		else if(start < end)
			end--;
		i++;
	}
	return(tab);
}
#include <stdio.h>
int main(void)
{
		int *tab = ft_rrange(-1, 2);
		for(int i = 0; i < 4; i++)
			printf("%d ", tab[i]);
		free(tab);
	return(0);
}
