/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:44:11 by amennad           #+#    #+#             */
/*   Updated: 2023/09/20 13:06:43 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>

void	manage_game(t_data *data)
{
	t_window	window;
	int			image_width;
	int			image_heigth;
	char		**map;
	int			nb_line;
	int			len_line;

	map = data->map;
	nb_line = data->nb_line;
	len_line = data->len_line;
	image_width = len_line * 50;
	image_heigth = nb_line * 50;
	window = new_game(data, image_width, image_heigth, "so_long");
	//taille de la fenetre
	if (!window.mlx_ptr || !window.win_ptr)
		ft_exit_free(1, map, NULL, "Error\nmlx_init() failed\n");
	//AFFICHER DES PIXELS
	print_pixel(window, image_width, image_heigth);
	//AFFICHER UNE IMAGE
	print_img(window, "./game/flower.xpm", (10), (10));
	//position dans l'ecran
	//AFFICHER PLUSIEURS IMAGES
	/*
	// int i = 0;
	// int j;
	// printf("lenline = %d\n", data.lenline);
	//
	// // print_img(window, "./game/flower.xpm", 0, 0);
	// while (i < data.nbline)
	// {
	// 	print_img(window, "./game/flower.xpm", 0, i * 32);
	// 	if (i == 0 || i == data.nbline - 1)
	// 	{
	// 		j = 1;
	// 		while (j < data.lenline - 1)
	// 		{
	// 			print_img(window, "./game/flower.xpm", j * 32, 0);
	// 			j++;
	// 		}
	// 	}
	// 	i++;
	// }*/
	// system("leaks so_long");
	mlx_hook(window.win_ptr, 2, 0, ft_keyboard_event, &window);
	mlx_hook(window.win_ptr, 17, 0, ft_mouse_event, &window);
	mlx_loop(window.mlx_ptr);
}
