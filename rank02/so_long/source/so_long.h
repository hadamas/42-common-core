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

# define WALL "./images/wall"
# define COIN "./images/coin.xpm"
# define EXIT "./images/exit.xpm"
# define PLAYERF "./images/player.xpm"
//# define PLAYER_B "./images/.xpm"
//# define PLAYER_L "./images/.xpm"
//# define PLAYER_R "./images/.xpm"

typedef struct s_map
{
    char    **map;
    int         rows;
    int         columns;
    int         coin;
    int         exit;
    int         player;
}   t_map;

typedef struct  s_img
{
    void    *img_wall;
    void    *img_coin;
    void    *img_exit;
    void    *img_playerf;
    //void    *img_playerb;
    //void    *img_playerl;
    //void    *img_playerr;
}   t_img;

typedef struct  s_pos
{
    int     x;
    int     y;
}   t_pos;

typedef struct s_game
{
    void    *mlx;
    void    *mlx_win;
    int         moves;
    t_map   map;
    t_img   img;
    t_pos   pos;
    t_pos   pos_e;
}   t_game;

void    check_file(char *file);

#endif