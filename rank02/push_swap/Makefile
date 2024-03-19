
NAME = push_swap
LIBFT = ./libft/libft/libft.a
SRCS = ./src/push_swap/errors.c \
			./src/push_swap/init_a_to_b.c \
			./src/push_swap/init_b_to_a.c \
			./src/push_swap/push_swap.c \
			./src/push_swap/split.c \
			./src/push_swap/stack_init.c \
			./src/push_swap/stack_utils.c \
			./src/push_swap/push_swap.c \
			./src/commands/rev_rotate.c \
			./src/commands/rotate.c \
			./src/commands/sort_stacks.c \
			./src/commands/sort_three.c \
			./src/commands/swap.c

OBJS = $(SRCS: .c=.o) 
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) 
		@make -s -C ./libft/libft/
		$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)		

clean:
		@make -s -C clean /libft/
		$(RM) $(OBJS)

fclean: 
		$(RM) $(NAME) $(LIBFT)
		 @make -s -C fclean /libft/

re: fclean all

.PHONY:	all clean fclean re