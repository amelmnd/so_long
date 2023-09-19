/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:44:11 by amennad           #+#    #+#             */
/*   Updated: 2023/09/19 11:37:34 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>

void	manage_game(char **map, int nb_line, int len_line)
{
	t_window window;
	int image_width;
	int image_heigth;

	image_width = len_line * 100;
	image_heigth = nb_line * 100;
	window = new_game(image_width, image_heigth, "so_long");
	//taille de la fenetre
	if (!window.mlx_ptr || !window.win_ptr)
		ft_exit_free(1, map, NULL, "Error\nmlx_init() failed\n");

	//AFFICHER DES PIXELS
	print_pixel(window, image_width, image_heigth);

	//AFFICHER UNE IMAGE
	print_img(window, "./game/flower.xpm", (10), (10)); //position dans l'ecran
	mlx_hook(window.win_ptr, 2, 0, ft_keyboard_event, &window);
	mlx_hook(window.win_ptr, 17, 0, ft_mouse_event, &window);
	mlx_loop(window.mlx_ptr);
}