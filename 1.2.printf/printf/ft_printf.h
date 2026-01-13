/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:20:16 by uuenkhba          #+#    #+#             */
/*   Updated: 2025/11/25 19:16:48 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_str(char *s);
int		ft_print_ptr(void *p);
int		ft_print_nbr(long n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned long n, char format); // 'x' or 'X'
int		ft_putnbr_base_count(unsigned long n, char *base);
int		ft_strlen(const char *s);
void	ft_putstr(char *s);

#endif
