/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:54:21 by ahadama-          #+#    #+#             */
/*   Updated: 2024/04/02 14:54:25 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void    init_window(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        exit(1);
    game->mlx_win = mlx_new_window(game->mlx_win, game->map.columns * 50, game->map.rows * 50, "Game");
    if (!game->mlx_win)
    {
        free(game->mlx_win);
        exit(1);
    }
}

int     keyboard(int key,t_game *game)
{
    if (key == ESC)
        close_window(game, 1);
    else
        move_player(game, key);
    if (game->map.coin == 0 && game->map.map[game->pos.y][game->pos.x] == 'E')
        close_window(game, 1);
    return (0);
}

void	error_msg(t_game *game, char c, int img)
{
	if (c == 'M')
	{
		ft_printf("Error: Map\n");
		free_map(game->map.map);
		exit(1);
	}
	close_window(game, img);
	exit(1);
}

int     main(int ac, char *av[])
{
    t_game  game;

    if (ac != 2)
    {
        ft_printf("Wrong input, please try: ./so_long file.ber\n");
        exit(1);
    }
    check_file(av[1]);
    init_map(&game, av[1]);
    init_window(&game);
    draw_map(&game);
}