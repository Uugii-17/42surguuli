NAME = push_swap

SRCS = push_swap.c operations.c sort.c utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
fclean: 
	clean rm -f $(NAME)

re:
	fclean all

.PHONY: 
	all clean fclean re
