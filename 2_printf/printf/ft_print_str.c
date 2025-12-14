// ft_print_str.c
#include "ft_printf.h"

int	ft_print_str(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}
