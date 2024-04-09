/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:05:28 by ahadama-          #+#    #+#             */
/*   Updated: 2024/04/05 14:05:30 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_ber(char *file)
{
    int fd;
    int i;
    
    i = ft_strlen(file);
    if (file[i - 1] != 'r' && file[i - 2] != 'e'
            && file[i - 3] != 'b' && file[i - 4] != '.')
    {
        ft_printf("Error: File extension not supported.\n");
        exit(1);
    }
    fd = open (file, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error: Map not found.\n");
        exit(1);
    }
    close(fd);
}

void    check_file(char *file)
{
    int fd;

    check_ber(file);
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error: .ber file not found\n");
        exit(1);
    }
    close(fd);
}