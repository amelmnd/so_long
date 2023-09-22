/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:55:10 by amennad           #+#    #+#             */
/*   Updated: 2023/09/22 09:30:42 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_view(t_window *window, int i, int j, int status)
{
	char	**array;
	int		tile_size;

	array = window->data->map;
	tile_size = window->tile_size;
	if (array[i][j] == 'P' && window->data->collected)
	{
		print_img(*window, "./assets/p_c.xpm", j * tile_size, i * tile_size);
		window->data->collected = 0;
	}
	else if (array[i][j] == 'P' && status == 'u')
		print_img(*window, "./assets/p_top.xpm", j * tile_size, i * tile_size);
	else if (array[i][j] == 'P' && status == 'l')
		print_img(*window, "./assets/p_lefth1.xpm", j * tile_size, i
			* tile_size);
	else if (array[i][j] == 'P' && status == 'r')
		print_img(*window, "./assets/p_rigth1.xpm", j * tile_size, i
			* tile_size);
	else if (array[i][j] == 'P' && status == 'd')
		print_img(*window, "./assets/p_down.xpm", j * tile_size, i * tile_size);
}

void	castel_not_finished(t_window *window, int i, int j, int tile_size)
{
	if (i == window->data->end_line && j == window->data->end_col
		&& window->data->player_line == window->data->end_line
		&& window->data->player_col == window->data->end_col)
		print_img(*window, "./assets/e_p.xpm", j * tile_size, i * tile_size);
}

void	design_gaming(t_window *window, char status)
{
	int		i;
	int		j;

	i = 0;
	while (window->data->map[i])
	{
		j = 0;
		while (window->data->map[i][j])
		{
			print_img(*window, "./assets/1.xpm", 0, 0);
			mlx_string_put(window->mlx_ptr, window->win_ptr, 7, 19, 0x0941616,
				ft_itoa(window->data->nb_move));
			if (window->data->map[i][j] == '0')
				print_img(*window, "./assets/0.xpm", j * window->tile_size, i
					* window->tile_size);
			else if (window->data->map[i][j] == 'E')
				print_img(*window, "./assets/e.xpm", j * window->tile_size, i
					* window->tile_size);
			player_view(window, i, j, status);
			castel_not_finished(window, i, j, window->tile_size);
			j++;
		}
		i++;
	}
}

int	ft_mouse_event(t_window *window)
{
	if (window)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}

int	ft_keyboard_event(int keycode, t_window *window)
{
	char	status;

	status = '0';
	if (keycode == 53)
	{
		if (window)
			mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 13 || keycode == 126 || keycode == 6)
		ft_move_up(window->data, &status);
	else if (keycode == 1 || keycode == 125)
		ft_move_down(window->data, &status);
	else if (keycode == 0 || keycode == 123 || keycode == 12)
		ft_move_left(window->data, &status);
	else if (keycode == 2 || keycode == 124)
		ft_move_right(window->data, &status);
	design_gaming(window, status);
	return (0);
}
