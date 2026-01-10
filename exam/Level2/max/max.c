int max(int* tab, unsigned int len)
{
	if(len == 0)
		return(0);
	int current_max = tab[0];
	unsigned int i = 1;
	while(i < len)
	{
		if(tab[i] >= current_max)
			current_max = tab[i];
		i++;
	}
	return(current_max);
}
#include <stdio.h>
int main()
{
	int tab[6] = {1, 2, 5, 10, 78};
	printf("%d\n", max(tab, 5));
}
