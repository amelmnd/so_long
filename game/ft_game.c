/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:44:11 by amennad           #+#    #+#             */
/*   Updated: 2023/09/22 11:04:32 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>

void	print_tile(t_window *window, int i, int j, char c_check)
{
	int	tile_size;

	tile_size = window->tile_size;
	if (c_check == '1')
		print_img(*window, "./assets/1.xpm", j * tile_size, i * tile_size);
	else if (c_check == '0')
		print_img(*window, "./assets/0.xpm", j * tile_size, i * tile_size);
	else if (c_check == 'C')
		print_img(*window, "./assets/c.xpm", j * tile_size, i * tile_size);
	else if (c_check == 'E')
		print_img(*window, "./assets/e.xpm", j * tile_size, i * tile_size);
	else if (c_check == 'P')
		print_img(*window, "./assets/p_down.xpm", j * tile_size, i * tile_size);
	else if (c_check == 'A')
		print_img(*window, "./assets/a.xpm", j * tile_size, i * tile_size);
}

void	design_game(t_window *window)
{
	int		i;
	int		j;
	char	**array;

	array = window->data->map;
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			print_tile(window, i, j, array[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_game(t_data *data)
{
	t_window	window;

	window = new_game(data, 40, "so_long");
	if (!window.mlx_ptr || !window.win_ptr)
		ft_exit_free(1, data->map, NULL, "Error\nmlx_init() failed\n");
	system("leaks so_long");
	design_game(&window);
	mlx_hook(window.win_ptr, 2, 0, ft_keyboard_event, &window);
	mlx_hook(window.win_ptr, 17, 0, ft_mouse_event, &window);
	mlx_loop(window.mlx_ptr);
}
