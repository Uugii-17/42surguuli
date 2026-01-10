#include <unistd.h>
int main(int ac, char **av)
{
	if(ac != 2)
	{
		write(1, "\n", 1);
		return(0);
	}
	int i = 0;
	int space = 0;
	while(av[1][i] == ' ' || av[1][i] == '\t')
		i++;
	while(av[1][i] != '\0')
	{
		if(av[1][i] != ' ' && av[1][i] != '\t')
		{
			if(space && (av[1][i - 1] == ' ' || av[1][i - 1] == '\t'))
				write(1, "   ", 3);
			write(1, &av[1][i], 1);
			space = 1;
		}
		i++;
	}
	write(1, "\n", 1);
	return(0);
}
