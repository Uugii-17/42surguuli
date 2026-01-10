void sort_int_tab(int *tab, unsigned int size)
{
	int tmp;
	unsigned int i, j;
	i = 0;
	while(i < size)
	{
		j = i + 1;
		while(j < size)
		{
			if(tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
#include <stdio.h>

int main(void)
{
    int tab[] = {5, -3, 42, 0, 7, 7, -8, 99, 1};
    unsigned int size = 9;
    unsigned int i = 0;

    printf("Before: ");
    while (i < size)
        printf("%d ", tab[i++]);
    printf("\n");

    sort_int_tab(tab, size);

    printf("After : ");
    i = 0;
    while (i < size)
        printf("%d ", tab[i++]);
    printf("\n");

    return (0);
}
