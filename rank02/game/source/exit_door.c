/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- ahadama-@student.42.rio           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:17:55 by ahadama-          #+#    #+#             */
/*   Updated: 2024/05/07 15:17:55 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_exit(t_game *data, int y, int x, char **map)
{
	if (x < 0 || y < 0 || x > data->map.columns || y > data->map.rows)
		return ;
	if (map[y][x] == 'P' || map[y][x] == '1' || map[y][x] == 'E')
		return ;
	map[y][x] = 'P';
	find_exit(data, y + 1, x, map);
	find_exit(data, y - 1, x, map);
	find_exit(data, y, x + 1, map);
	find_exit(data, y, x - 1, map);
}

int	check_around(int x, int y, char **map)
{
	if (map[y + 1][x] == 'P' || map[y - 1][x] == 'P' ||
		map[y][x + 1] == 'P' || map[y][x - 1] == 'P')
		return (0);
	return (1);
}

void	check_exit_around(t_game *data, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || data->map.map[i][j] == 'C')
			{
				if (check_around(j, i, map))
				{
					free_map(map);
					throw_error(data, 'M', 0);
				}
			}
			j++;
		}
		i++;
	}
}

void	check_exit_path(t_game *data, char *file)
{
	int		y;
	int		x;
	char	**map;

	y = data->pos.y;
	x = data->pos.x;
	map = create_map(file);
	find_exit(data, y + 1, x, map);
	find_exit(data, y - 1, x, map);
	find_exit(data, y, x + 1, map);
	find_exit(data, y, x - 1, map);
	find_exit(data, y, x, map);
	check_exit_around(data, map);
	free_map(map);
}
