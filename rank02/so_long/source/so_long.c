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

int main(int ac, char *av[])
{
    t_game  game;

    if (ac != 2)
    {
        printf("Wrong input, please try: ./so_long file.ber\n");
        exit(1);
    }
    check_file(av[1]);
    start_map(&game, av[1]);
}