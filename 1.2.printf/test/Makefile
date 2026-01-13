# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/25 17:13:29 by uuenkhba          #+#    #+#              #
#    Updated: 2025/11/25 19:15:17 by uuenkhba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS		= ft_printf.c\
		  ft_print_char.c\
		  ft_print_str.c\
		  ft_print_ptr.c\
		  ft_print_nbr.c\
		  ft_print_unsigned.c\
		  ft_print_hex.c\
		  ft_utils.c

OBJS = $(SRCS:%.c=%.o)

NAME = libftprintf.a

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re
