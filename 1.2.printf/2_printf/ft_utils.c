// ft_utils.c  ← Энд л гол нь байгаа
#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putnbr_base_count(unsigned long n, char *base)
{
	int	base_len = ft_strlen(base);
	int	count = 0;

	if (n >= (unsigned long)base_len)
		count += ft_putnbr_base_count(n / base_len, base);
	count += ft_print_char(base[n % base_len]);
	return (count);
}
