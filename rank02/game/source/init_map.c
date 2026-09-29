/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- ahadama-@student.42.rio           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:05:33 by ahadama-          #+#    #+#             */
/*   Updated: 2024/05/06 10:05:33 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_rows(t_game *data, char *file)
{
	char	*line;
	int		rows;
	int		fd;

	rows = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		free(line);
		rows++;
	}
	data->map.rows = rows;
	close(fd);
}

void	map_columns(t_game *data, char *file)
{
	char	*line;
	int		columns;
	int		fd;

	columns = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		ft_printf("Error: The .ber file is empty.\n");
		exit(1);
	}
	while (line[columns] != '\n')
		columns++;
	free(line);
	close(fd);
	data->map.columns = columns;
}

char	**create_map(char *file)
{
	int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;
	char	**map;

	fd = open(file, O_RDONLY);
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free(line);
		free(holder);
	}
	free(line);
	map = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
	return (map);
}

void	count_assets(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	data->map.person = 0;
	data->map.exit = 0;
	data->map.colection = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
				data->map.person++;
			else if (data->map.map[i][j] == 'E')
				data->map.exit++;
			else if (data->map.map[i][j] == 'C')
				data->map.colection++;
			j++;
		}
		i++;
	}
}

void	init_map(t_game *data, char *file)
{
	data->moves = 0;
	map_columns(data, file);
	map_rows(data, file);
	data->map.map = create_map(file);
	take_position(data);
	check_caracters(data);
	count_assets(data);
	check_rectangular(data);
	check_assets(data);
	check_walls(data);
	check_exit_path(data, file);
}
