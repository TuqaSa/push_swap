CC = cc
CFLAGS = -Wall -Werror -Wextra -g
CPPFLAGS = -I. -ILibft -Istack

# Stack directory files
STACK_DIR = stack/
STACK_SRCS = stack_init.c stack_utls.c parser.c oprations_utls.c swap.c push.c rotate.c rev_rotate.c error.c
STACK_OBJS = $(addprefix $(STACK_DIR), $(STACK_SRCS:.c=.o))

# Main source files
SRCS = push_swap.c sort.c chunk_sort.c chunk_split.c chunk_util.c move.c sort_three.c 
OBJS = $(SRCS:.c=.o)

NAME = push_swap 
LIBFT = ./Libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(STACK_OBJS) ${LIBFT}
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(STACK_OBJS) -L Libft -lft -o $(NAME)

${LIBFT}:
	make -C Libft

# Rule for main source files
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Rule for stack directory files
$(STACK_DIR)%.o: $(STACK_DIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(STACK_OBJS)
	make -C Libft clean

fclean: clean
	rm -f $(NAME)
	make -C Libft fclean

re: fclean all

.PHONY: all clean fclean re
