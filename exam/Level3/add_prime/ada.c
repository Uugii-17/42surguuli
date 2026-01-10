#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}
int ft_atoi(char *str)
{
	int i= 0;
	int sign = 1;
	int res = 0;
	while(str[i] <= 32)
		i++;
	if(str[i] == '+' && str[i] == '-')
	{
		if(str[i] == '-')
			sign = -1;
		i++;
	}
	while(str[i])
	{
		if(str[i] && str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - '0');
		i++;
	}
	return(res * sign);
}
int ft_putnb(int n)
{
	unsigned int nb;
	if(n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	if(nb >= 10)
		ft_putnb(nb / 10);
	ft_putchar(nb % 10 + '0');
	return(nb);
}
int is_prime(int n)
{
	if(n < 2)
		return(0);
	int i = 2;
	while(i <= n / 2)
	{
		if(n % i == 0)
			return (0);
		i++;
	}
	return (1);
}
int main(int ac, char **av)
{
	if(ac != 2 || ft_atoi(av[1]) <= 0)
	{
		write(1, "0\n", 2);
		return(0);
	}
	int sum = 0;
	int n = ft_atoi(av[1]);
	while(n > 1)
	{
		if(is_prime(n))
			sum += n;	
		n--;
	}
	ft_putnb(sum);
	ft_putchar('\n');
	return(0);
}
