#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}
int main(int ac, char **av)
{
	if(ac != 2 || (av[1][0] >= 'A' && av[1][0] <= 'Z'))
	{
		ft_putchar('\n');
		return(0);
	}
	while(av[1][i] != '\0')
	{
		while(av[1][i] == ' ' || av[1][i] == '\t')
		{
			i++;
		}
		if(av[1][i] >= 'A' && av[1][i] <= 'Z')
		{
			ft_putchar('_');
			av[1][i] += 32;
		}
		ft_putchar(av[1][i]);
		i++;
	}
	ft_putchar('\n');
	return(0);
}
