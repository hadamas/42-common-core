/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:10:14 by ahadama-          #+#    #+#             */
/*   Updated: 2024/04/20 14:10:17 by ahadama-         ###   ########.fr       */
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