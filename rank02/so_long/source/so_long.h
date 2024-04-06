/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:54:29 by ahadama-          #+#    #+#             */
/*   Updated: 2024/04/02 14:54:31 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libraries/printf/ft_printf.h"
#include "../libraries/libft/libft/libft.h"
#include "../libraries/minilibx-linux/mlx.h"
#include "../libraries/gnl/get_next_line.h"

#include <stdlib.h>
#include <unistd.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
    char    **map;
    int         rows;
    int         columns;
    int         coins;
    int         exit;
    int         player;
}   t_map;

typedef struct  s_pos
{
    int     x;
    int     y;
}   t_pos;

typedef struct s_game
{
    void    *ptr_mlx;
    void    *w_mlx;
    int         moves;
    t_map   map;
    t_pos   pos;
}   t_game;


void    check_file(char *file);

#endif