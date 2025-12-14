// ft_print_ptr.c
#include "ft_printf.h"

int	ft_print_ptr(void *p)
{
	if (!p)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	return (2 + ft_putnbr_base_count((unsigned long)p, "0123456789abcdef"));
}
