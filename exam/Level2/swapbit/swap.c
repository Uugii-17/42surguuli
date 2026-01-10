#include <unistd.h>
unsigned char swap_bits(unsigned char octet)
{
	return((octet >> 4) | (octet << 4));
}
void printbit(unsigned char octet)
{
	int i = 8;
	while(i--)
	{
		if(octet & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}
int main()
{
	printbit(66);
	write(1, "\n", 1);
	printbit(swap_bits(66));
}
