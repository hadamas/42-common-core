# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 14:37:50 by ahadama-          #+#    #+#              #
#    Updated: 2023/11/13 15:45:45 by ahadama-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printdigit.c

OBJS = $(SRCS:.c = .o)

all: $(NAME)

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean


re: fclean all

.PHONY: all clean fclean re
