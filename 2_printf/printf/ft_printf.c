// ft_printf.c
#include "ft_printf.h"

static int	ft_handle_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				count += ft_handle_format(args, format[i]);
			else
				return (count);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
