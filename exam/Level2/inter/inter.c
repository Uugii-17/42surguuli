#include <unistd.h>
int main(int ac, char **av)
{
	if(ac == 3)
	{
		int i = 0;
		int j;
		int seen[256] = {};
		while(av[1][i] != '\0')
		{
			j = 0;
			while(av[2][j] != '\0')
			{
				if(av[1][i] == av[2][j] && !seen[(int)av[2][j]])
				{
					seen[(int)av[2][j]] = 1;
					write(1, &av[2][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
