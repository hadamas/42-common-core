/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:50:27 by ahadama-          #+#    #+#             */
/*   Updated: 2024/04/09 10:50:30 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
}


int     close_window(t_game *game, int img)
{
    free_map(game->map.map);
    if (img)
    {
        mlx_destroy_image(game->mlx, game->img.img_wall);
		mlx_destroy_image(game->mlx, game->img.img_coin);
		mlx_destroy_image(game->mlx, game->img.img_exit);
		mlx_destroy_image(game->mlx, game->img.img_playerf);
		//mlx_destroy_image(game->mlx, game->img.img_playerb);
		//mlx_destroy_image(game->mlx, game->img.img_playerl);
		//mlx_destroy_image(game->mlx, game->img.img_playerr);
    }
    mlx_destroy_window(game->mlx, game->mlx_win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(0);
    return (0);
}