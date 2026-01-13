// ft_print_unsigned.c
#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	return (count + ft_print_char("0123456789"[n % 10]));
}
