/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- ahadama-@student.42.rio           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:09:17 by ahadama-          #+#    #+#             */
/*   Updated: 2024/05/06 12:09:17 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_images(t_game *data)
{
	data->img.img_gram = mlx_xpm_file_to_image(data->ptr_mlx,
			GRAM, &data->map.columns, &data->map.rows);
	data->img.img_tree = mlx_xpm_file_to_image(data->ptr_mlx,
			TREE, &data->map.columns, &data->map.rows);
	data->img.img_kidf = mlx_xpm_file_to_image(data->ptr_mlx,
			KID_F, &data->map.columns, &data->map.rows);
	data->img.img_kidb = mlx_xpm_file_to_image(data->ptr_mlx,
			KID_B, &data->map.columns, &data->map.rows);
	data->img.img_kidl = mlx_xpm_file_to_image(data->ptr_mlx,
			KID_L, &data->map.columns, &data->map.rows);
	data->img.img_kidr = mlx_xpm_file_to_image(data->ptr_mlx,
			KID_R, &data->map.columns, &data->map.rows);
	data->img.img_exit = mlx_xpm_file_to_image(data->ptr_mlx,
			EXIT, &data->map.columns, &data->map.rows);
	data->img.img_pok = mlx_xpm_file_to_image(data->ptr_mlx,
			POK, &data->map.columns, &data->map.rows);
}

void	put_image(t_game *data, char px, int x, int y)
{
	if (px == '1')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_tree, x * 50, y * 50);
	else if (px == '0')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_gram, x * 50, y * 50);
	else if (px == 'C')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_pok, x * 50, y * 50);
	else if (px == 'E')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_exit, x * 50, y * 50);
	else if (px == 'P')
		mlx_put_image_to_window(data->ptr_mlx, data->w_mlx,
			data->img.img_kidf, x * 50, y * 50);
}

void	draw_map(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	render_images(data);
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			put_image(data, data->map.map[i][j], j, i);
			j++;
		}
		i++;
	}
}
