/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:55:10 by amennad           #+#    #+#             */
/*   Updated: 2023/09/20 15:21:00 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mouse_event(t_window *window)
{
	if (window)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}

int	ft_keyboard_event(int keycode, t_window *window)
{
	if (keycode == 53)
	{
		if (window)
			mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 13 || keycode == 126 || keycode == 6)
	{
		ft_move_up(window->data);
		printf("\nup\n");
		print_map(window->data->map);
	}
	else if (keycode == 1 || keycode == 125)
	{
		ft_move_down(window->data);
		printf("\ndown\n");
		print_map(window->data->map);
	}
	else if (keycode == 0 || keycode == 123 || keycode == 12)
	{
		ft_move_left(window->data);
		printf("\nleft\n");
		print_map(window->data->map);
	}
	else if (keycode == 2 || keycode == 124)
	{
		ft_move_right(window->data);
		printf("\nrigth\n");
		print_map(window->data->map);
	}
	return (0);
}
