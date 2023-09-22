/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:24:27 by amennad           #+#    #+#             */
/*   Updated: 2023/09/22 11:36:32 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	new_game(t_data *data, int tile_size, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_window){mlx_ptr, mlx_new_window(mlx_ptr, data->len_line
			* tile_size, data->nb_line * tile_size, str), data->len_line
		* tile_size, data->nb_line * tile_size, tile_size, data});
}

void	collect_item(char position, t_data *data)
{
	if (position == 'C')
	{
		data->nb_collected += 1;
		data->collected = 1;
	}
	if (data->nb_collected == data->nb_item)
	{
		data->not_finish = 0;
	}
}

int	check_position(t_data *data, char position)
{
	if (position == '0')
		return (1);
	else if (position == 'C')
		return (1);
	else if (position == '1')
	{
		return (0);
	}
	else if (position == 'E' && data->nb_collected != data->nb_item)
	{
		data->not_finish = 1;
		return (1);
	}
	else if (position == 'E' && data->nb_collected == data->nb_item)
	{
		return (-1);
	}
	return (0);
}

void	print_img(t_window window, char *path, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(window.mlx_ptr, path, &img_width, &img_height);
	if (!img)
		printf("Error2\n");
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, img, x, y);
}
