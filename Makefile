#Variables

NAME = test
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
AFLAGS = rcs

#Files

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

#Commands

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(AFLAGS) $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re