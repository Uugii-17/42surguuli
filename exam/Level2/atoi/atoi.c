int ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;
	res = 0;
	sign = 1;
	i = 0;
	while(str[i] != '\0')
	{
		while((str[i] == ' ' || str[i] == '\t')
			i++;
		while(str[i] == '-')
		{
			sign *= -1;
			i++;
		}
		while(str[i] >= 33 && str[i] <= 126)
		{
			if(str[i] >= '0' && str[i] <= '9')
				res = res * 10 + (str[i] - '0');
			i++;
		}
	}
	return(res * sign);
}
#include <stdio.h>
int main(int ac, char **av)
{
	if(ac == 2)
	{
		printf("%d\n", ft_atoi(av[1]));
	}
	printf("\n");
	return(0);
}
