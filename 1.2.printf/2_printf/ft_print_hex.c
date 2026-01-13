// ft_print_hex.c
#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char format)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (ft_putnbr_base_count(n, base));
}
