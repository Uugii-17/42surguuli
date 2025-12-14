#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

// Туслах функцууд
int		ft_print_char(int c);
int		ft_print_str(char *s);
int		ft_print_ptr(void *p);
int		ft_print_nbr(long n);
int		ft_print_unsigned(unsigned int n);
int);
int		ft_print_hex(unsigned long n, char format);
int		ft_putnbr_base_count(unsigned long n, char *base);
int		ft_strlen(const char *s);
void	ft_putstr(char *s);

#endif
