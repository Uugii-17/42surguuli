#include <stdlib.h>
int *ft_range(int start, int end)
{
	int size = 0;
	int i = 0;
	int *tab;
	if(end >= start)
		size = end - start + 1;
	else
		size = start - end + 1;
	tab = malloc(sizeof(int) * size);
	if(!tab)
		return NULL;
	while(i < size)
	{
		tab[i] = start;
		if(start < end)
			start++;
		else
			start--;
		i++;
	}
	return(tab);
}
