#include <unistd.h>
int putnb(int n)
{
	unsigned int num;
	if(n < 0)
		num = -n;
	else
		num = n;
	if(num >= 10)
		putnb(num / 10);
	char c = num % 10 + '0';
	return(write(1, &c, 1));
}
int main(void)
{
	int i = 1;
	while(i <= 100)
	{
		if(i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if(i % 3 == 0)
			write(1, "fizz", 4);
		else if(i % 5 == 0)
			write(1, "buzz", 4);
		else
			putnb(i);
		write(1, "\n", 1);
		i++;
	}
}
