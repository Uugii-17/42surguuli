int ft_atoi_base(const char *str, int str_base)
{
	int res = 0;
	int sign = 1;
	int digit_value;
	if(str_base < 2 || str_base > 16)
		return (0);
	while(*str == ' ' || *str == '\t')
		str++;
	if(*str == '-' || *str == '+')
	{
		if(*str == '-')
			sign = -1;
		str++;
	}
	while(*str)
	{
		digit_value = -1;
		if(*str >= '0' && *str <= '9')
			digit_value = *str - '0';
		else if(*str >= 'A' && *str <= 'F')
			digit_value = *str - 'A' + 10;
		else if(*str >= 'a' && *str <= 'f')
			digit_value = *str - 'a' + 10;
		if(digit_value == -1 || digit_value >= str_base)
			break;
		res = res * str_base + digit_value;
		str++;
	}
	return(sign * res);
}
#include <stdio.h>
int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if(ac == 3)
	{
		printf("%d\n", ft_atoi_base(av[1], ft_atoi_base(av[2], 10)));
	}
	return 0;
}
