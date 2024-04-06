/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:26:15 by ahadama-          #+#    #+#             */
/*   Updated: 2024/04/05 14:26:17 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_map_columns(t_game *game, char *file)
{
    char    *line;
    int         columns;
    int         fd;

    columns = 0;
    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    if (!line)
    {
        free(line);
        ft_printf("Error: Empty .ber file.\n");
        exit(1);
    }
    while (line[columns] != '\n')
        columns++;
    free(line);
    close(fd);
    game->map.columns = columns;
}

void    get_map_rows(t_game *game, char *file)
{
    char *line;
    int     rows;
    int     fd;

    rows = 0;
    fd = open(file, O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (!fd)
        {
            free(line);
            break ;
        }
        free(line);
        rows++;
    }
    game->map.rows = rows;
    close(fd);
}

char   **create_map(file)
{
    int         fd;
    char    *line;
    char    *
}

void    start_map(t_game *game, char *file)
{
    game->moves = 0;
    get_map_columns(game, file);
    get_map_rows(game, file);
    game->map.map = create_map(file);
}