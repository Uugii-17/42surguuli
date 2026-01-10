#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	if(ac != 4 || av[2][0] == 0 || av[2][1] != '\0')
	{
		printf("\n");
		return(0);
	}
	int num1 = atoi(av[1]);
	char op = av[2][0];
	int num2 = atoi(av[3]);
	int res = 0;
	if(op == '+')
	{
		res = num1 + num2;
	}
	else if(op == '-')
	{
		res = num1 - num2;
	}
	else if(op == '*')
	{
		res = num1 * num2;
	}
	else if(op == '/')
	{
		if(num2 < 0)
		{
			printf("\n");
			return(0);
		}
		res = num1 / num2;
	}
	else if(op == '%')
	{
		if(num2 < 0)
		{
			printf("\n");
			return(0);
		}
		res = num1 % num2;
	}
	printf("%d\n", res);
	return(0);
}
