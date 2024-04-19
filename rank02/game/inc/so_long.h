/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:33:19 by ahadama-          #+#    #+#             */
/*   Updated: 2024/04/19 14:02:57 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG


# include "../lib/libftprintf/ft_printf.h"
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>


typedef struct	s_game
{
	int	row;
	int	col;
	int	mov;
	int	fd;
	void	**map;
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*coin;
	void	*floor;
	void	*wall;
	void	*exit;
}	t_game;

#endif