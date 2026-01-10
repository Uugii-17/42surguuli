#include <unistd.h>
unsigned char reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char res = 0;
	while(i--)
	{
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return(res);
}
void printb(unsigned char octet)
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
#include <unistd.h>
int main()
{
	printb(38);
	write(1, "\n", 1);
	printb(reverse_bits(38));
}
