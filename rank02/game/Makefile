# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadama- ahadama-@student.42.rio           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 14:54:38 by ahadama-          #+#    #+#              #
#    Updated: 2024/04/02 14:56:13 by ahadama-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SOURCE = ./source/
SO_LONG_C = $(SOURCE)so_long.c\
			$(SOURCE)init_map.c\
			$(SOURCE)error.c\
			$(SOURCE)exit_game.c\
			$(SOURCE)draw_map.c\
			$(SOURCE)move.c\
			$(SOURCE)check_file.c\
			$(SOURCE)exit_door.c

LIBMLX = ./libraries/minilibx-linux/
LIBMLX_A = $(LIBMLX)libmlx_Linux.a
LIBFT = ./libraries/libft/
LIBFT_A = $(LIBFT)libft.a
FT_PRINTF = ./libraries/ft_printf/
FT_PRINTF_A = $(FT_PRINTF)libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lXext -lX11
RM = rm -rf

all: $(NAME)

$(NAME):
		$(MAKE) -C $(LIBFT)
		$(MAKE) -C $(FT_PRINTF)
		$(MAKE) -C $(LIBMLX)
		$(CC) $(CFLAGS) $(SO_LONG_C) $(LIBMLX_A) $(LIBFT_A) $(FT_PRINTF_A) $(MLXFLAGS) -o $(NAME)

clean:
		@$(MAKE) clean -C $(LIBFT)
		@$(MAKE) clean -C $(FT_PRINTF)
		@$(MAKE) clean -C $(LIBMLX)

fclean: clean
		@$(MAKE) fclean -C $(LIBFT)
		@$(MAKE) fclean -C $(FT_PRINTF)
		$(RM) $(NAME)

re: 	fclean all

.PHONY:	all clean fclean re