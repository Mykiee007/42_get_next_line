#Variables

NAME = test
CC = cc
CFLAGS = -Wall -Wextra -Werror
#AR = ar
#AFLAGS = rcs

#Files

SRCS = get_next_line.c get_next_line_utils.c main.c
#OBJS = $(SRCS:.c=.o)

#Commands

all: $(NAME)

$(NAME): main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re