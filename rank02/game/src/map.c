/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:48:19 by ahadama-          #+#    #+#             */
/*   Updated: 2024/04/19 17:48:21 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


void    map_row(t_game *data, char *map_file)
{
    char    *temp;
    int     rows;
    int     fd;

    rows = 0;
    fd = open(map_file, O_RDONLY);
    while (1)
    {
        temp = get_next_line(fd);
        if (!temp)
        {
            free(temp);
            break ;
        }
        free(temp);
        rows++;
    }
    data->row = rows;
    close(fd);
}

void  map_col(t_game *data, char *map_file)
{
    char    *line;
    int     col;
    int     fd;

    col = 0;
    fd = open(map_file, O_RDONLY);
    line = get_next_line(fd);
    if (!line)
    {
        free(line);
        ft_printf("Error: The map is empty.\n");
        exit(1);
    }
    while (line[col] != '\n')
        col++;
    free(line);
    close(fd);
    data->col = col;
}


int read_map(t_game *data, char *map_file)
{
    if (file_check(map_file) == 1)
    {
        ft_printf("Error: File extension not supported.\n");
        exit(1);
    }
    data->fd = open(map_file, O_RDONLY);
    if (!data->fd)
    {
        ft_printf("Error: file not found.\n");
        exit(1);
    }
    map_row(data, map_file);
    /*if (!data->map)
    {
        ft_printf("Error: Map not supported.\n");
        free_map(data);
    }*/
    close(data->fd);
    data->col = map_col(data->map[0]);
    return (0);
}