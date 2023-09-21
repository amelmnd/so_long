/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:55:10 by amennad           #+#    #+#             */
/*   Updated: 2023/09/21 13:18:26 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mouse_event(t_window *window)
{
	if (window)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}

void	design_gaming(t_window *window, char status)
{
	int		i;
	int		j;
	char	**array;

	array = window->data->map;
	printf("status = %c\n", status);
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '0')
				print_img(*window, "./asset/background_2.xpm", j
						* window->tile_size, i * window->tile_size);
			else if (array[i][j] == 'E')
				print_img(*window, "./asset/castel_2.xpm", j
						* window->tile_size, i * window->tile_size);
			if (array[i][j] == 'P' && status == 'u')
				print_img(*window, "./asset/pitch_top_2.xpm", j
						* window->tile_size, i * window->tile_size);
			else if (array[i][j] == 'P' && status == 'l')
				print_img(*window, "./asset/pitch_lefth_2.xpm",
						j*window->tile_size, i*window->tile_size);
			else if (array[i][j] == 'P' && status == 'r')
				print_img(*window, "./asset/pitch_rigth_2.xpm",
						j*window->tile_size, i*window->tile_size);
			else if (array[i][j] == 'P' && status == 'd')
				print_img(*window, "./asset/pitch_down_2.xpm",
						j*window->tile_size, i*window->tile_size);
			if (i == window->data->end_line && j == window->data->end_col
				&& window->data->player_line == window->data->end_line
				&& window->data->player_col == window->data->end_col)
				print_img(*window, "./asset/castel_pitch_2.xpm", j
						* window->tile_size, i * window->tile_size);
			j++;
		}
		i++;
	}
}

int	ft_keyboard_event(int keycode, t_window *window)
{
	char status; // 4 status : left = l, right = r, up = u, down = d
	status = '0';
	if (keycode == 53)
	{
		if (window)
			mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 13 || keycode == 126 || keycode == 6)
	{
		window->data->nb_move++;
		ft_move_up(window->data);
		status = 'u';
	}
	else if (keycode == 1 || keycode == 125)
	{
		window->data->nb_move++;
		ft_move_down(window->data);
		status = 'd';
	}
	else if (keycode == 0 || keycode == 123 || keycode == 12)
	{
		window->data->nb_move++;
		ft_move_left(window->data);
		status = 'l';
	}
	else if (keycode == 2 || keycode == 124)
	{
		window->data->nb_move++;
		ft_move_right(window->data);
		status = 'r';
	}
	ft_printf("%d\n", window->data->nb_move);
	design_gaming(window, status);

	return (0);
}
