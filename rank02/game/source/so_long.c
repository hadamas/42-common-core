/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- ahadama-@student.42.rio           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:50:21 by ahadama-          #+#    #+#             */
/*   Updated: 2024/05/01 09:50:21 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initializing_window(t_game *data)
{
	data->ptr_mlx = mlx_init();
	if (!data->ptr_mlx)
		exit(1);
	data->w_mlx = mlx_new_window(data->ptr_mlx,
			data->map.columns * 50, data->map.rows * 50, "Pokemon");
	if (!data->w_mlx)
	{
		free(data->ptr_mlx);
		exit(1);
	}
}

int	on_keypress(int key, t_game *data)
{
	if (key == ESC)
		destroy_window(data, 1);
	else
		move(data, key);
	if (data->map.colection == 0
		&& data->map.map[data->pos.y][data->pos.x] == 'E')
		destroy_window(data, 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
	{
		ft_printf("Wrong initialization\nEx: ./so_long file.ber\n");
		exit(1);
	}
	check_file(av[1]);
	init_map(&data, av[1]);
	initializing_window(&data);
	draw_map(&data);
	mlx_key_hook(data.w_mlx, on_keypress, &data);
	mlx_hook(data.w_mlx, 17, 0, destroy_window, &data);
	mlx_loop(data.ptr_mlx);
	return (0);
}
