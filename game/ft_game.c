/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:44:11 by amennad           #+#    #+#             */
/*   Updated: 2023/09/21 13:12:42 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>

void design_game(t_window *window)
{
	int	i;
	int	j;
	char **array = window->data->map;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '1')
				print_img(*window, "./asset/wall_ligth_2.xpm", j*window->tile_size, i*window->tile_size);
			else if (array[i][j] == '0')
				print_img(*window, "./asset/background_2.xpm", j*window->tile_size, i*window->tile_size);
			else if (array[i][j] == 'C')
				print_img(*window, "./asset/todd_2.xpm", j*window->tile_size, i*window->tile_size);
			else if (array[i][j] == 'E')
				print_img(*window, "./asset/castel_2.xpm", j*window->tile_size, i*window->tile_size);
			else if (array[i][j] == 'P')
				print_img(*window, "./asset/pitch_down_2.xpm", j*window->tile_size, i*window->tile_size);
			j++;
		}
		i++;
	}
}

void	ft_game(t_data *data)
{
	t_window	window;

	window = new_game(data, 40, "so_long");

	//taille de la fenetre
	if (!window.mlx_ptr || !window.win_ptr)
		ft_exit_free(1, data->map, NULL, "Error\nmlx_init() failed\n");
	system("leaks so_long");
	design_game(&window);
	mlx_hook(window.win_ptr, 2, 0, ft_keyboard_event, &window);
	mlx_hook(window.win_ptr, 17, 0, ft_mouse_event, &window);
	mlx_loop(window.mlx_ptr);
}
