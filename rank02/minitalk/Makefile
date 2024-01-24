# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 16:37:08 by ahadama-          #+#    #+#              #
#    Updated: 2024/01/24 16:45:31 by ahadama-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAMEC = client
NAMES = server

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(NAMEC) $(NAMES)

$(NAMEC):
	$(CC) $(CFLAGS) -o $(NAMEC) client.c utils.c

$(NAMES):
	 $(CC) $(CFLAGS) -o $(NAMES) server.c utils.c

clean:
	$(RM) $(NAMEC) && $(RM) $(NAMES)

fclean: clean
	clear

re: fclean all

.PHONY: all clean fclean re
