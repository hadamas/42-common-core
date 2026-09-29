# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 17:17:51 by ahadama-          #+#    #+#              #
#    Updated: 2024/03/28 10:58:00 by ahadama-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ./libft/libft/libft.a
SRCS = ./src/push_swap/errors.c \
       ./src/push_swap/init_a_to_b.c \
       ./src/push_swap/init_b_to_a.c \
       ./src/push_swap/split.c \
       ./src/push_swap/stack_init.c \
       ./src/push_swap/stack_utils.c \
       ./src/push_swap/push_swap.c \
       ./src/commands/push.c \
       ./src/commands/rev_rotate.c \
       ./src/commands/rotate.c \
       ./src/commands/sort_stacks.c \
       ./src/commands/sort_three.c \
       ./src/commands/swap.c

OBJS = $(SRCS:.c=.o) 
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) 
		@make -s -C ./libft/libft/
		$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)		

clean:
		@make -s -C ./libft/libft/ clean
		$(RM) $(OBJS)

fclean: 
		$(RM) $(NAME) $(LIBFT)
		@make -s -C ./libft/libft/ fclean

re: fclean all

.PHONY:	all clean fclean re
