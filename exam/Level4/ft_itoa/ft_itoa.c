#include <stdlib.h>
int num_len(int n)
{
	int i = 0;
	if(n <= 0)
		i++;
	while(n != 0)
	{
		n = n / 10;
		i++;
	}
	return(i);
}
char *ft_itoa(int nbr)
{
	int i;
	int len;
	int num;
	char *str;
	num = nbr;
       len = num_len(nbr);
       str = malloc(sizeof(char) * (len + 1));
       if(!str)
	       return(NULL);
       str[len] = '\0';
       i = len - 1;
       if(num < 0)
       {
	       str[0] = '-';
	        num = -num;
       }
       while(num > 0)
       {
	       str[i] = num % 10 + '0';
	       num = num / 10;
	       i--;
       }
       str[i] = num + '0';
       return(str);
}
