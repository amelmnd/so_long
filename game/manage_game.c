/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:44:11 by amennad           #+#    #+#             */
/*   Updated: 2023/09/18 18:32:41 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	manage_game(char **map, int nb_line, int len_line)
{
	t_window window;
	t_img image;

	window = new_game((len_line * 100), (nb_line * 100), "so_long");
	if (!window.mlx_ptr || !window.win_ptr)
		ft_exit_free(1, map, NULL, "Error\nmlx_init() failed\n");
	image = new_img((len_line * 100), (nb_line * 100), window);
	put_pixel_img(image, 250, 100, 0x00FFFFFF);
	mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr, image.img_ptr,
			0, 0);
	mlx_hook(window.win_ptr, 2, 0, ft_keyboard_event, &window);
	mlx_hook(window.win_ptr, 17, 0, ft_mouse_event, &window);
	mlx_loop(window.mlx_ptr);
}