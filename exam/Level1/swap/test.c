void ft_swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
#include <stdio.h>
int main()
{
	int a = 2;
	int b = 3;
	ft_swap(&a, &b);
	printf("%d %d\n", a , b);
}
