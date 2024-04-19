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

int file_check(char *map_file)
{
    int i;

    i = ft_strlen(map_file);
    if (map_file[i - 1] != 'r' && map_file[i - 2] != 'e'
            && map_file[i - 3] != 'b' && map_file[i - 4] != '.')
        return (1);
    return(0);
}

static int  new_line(t_game *data, char *readmap)
{
    char    **temp;
    int     i;

    if (!readmap)
        return (0);
    i = 0;
    data->row++;
    temp = (char *)malloc(sizeof(char *) * (data->row + 1));
    if (!temp)
        return (0);
    while (i < data->row - 1)
    {
        temp[i] = data->map[i];
        i++;
    }
    temp[i] = *readmap; //????????????
    if (data->map)
        free(data->map);
    data->map = temp;
    return (1);
}

static int  map_col(char *str)
{
    int cols;

    cols = 0;
    while (str[cols] != '\0' && str[cols] != '\n')
        cols++;
    return (cols);
}


int read_map(t_game *data, char *map_file)
{
    char *readmap;

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
    while (1)
    {
        readmap = get_next_line(data->fd);
        if (!new_line(data, readmap))
            break ;
    }
    if (!data->map)
    {
        ft_printf("Error: Map not supported.\n");
        free_map(data);
    }
    close(data->fd);
    data->col = map_col(data->map[0]);
    return (0);
}