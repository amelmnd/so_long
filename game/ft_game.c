/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:44:11 by amennad           #+#    #+#             */
/*   Updated: 2023/09/20 19:19:30 by amennad          ###   ########.fr       */
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
				print_img(*window, "./xpm/kawai_wall.xpm", j*32, i*32);
			// else if (array[i][j] == '0')
			// 	cyan();
			else if (array[i][j] == 'C')
				print_img(*window, "./xpm/piece.xpm", j*32, i*32);
			else if (array[i][j] == 'E')
				print_img(*window, "./xpm/castel.xpm", j*32, i*32);
			else if (array[i][j] == 'P')
				print_img(*window, "./xpm/flower.xpm", j*32, i*32);
			printf("%c ", array[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_game(t_data *data)
{
	t_window	window;
	// int			image_width;
	// int			image_heigth;
	// char		**map;
	// int			nb_line;
	// int			len_line;

	// map = data->map;
	// nb_line = data->nb_line;
	// len_line = data->len_line;
	// image_width = len_line * 32;
	// image_heigth = nb_line * 32;
	window = new_game(data, data->len_line * 32, data->nb_line * 32, "so_long");
	//taille de la fenetre
	if (!window.mlx_ptr || !window.win_ptr)
		ft_exit_free(1, data->map, NULL, "Error\nmlx_init() failed\n");
	//AFFICHER DES PIXELS
	// print_pixel(window, image_width, image_heigth);
	//AFFICHER UNE IMAGE
	// print_img(window, "./xpm/castel.xpm", 0, 32);
	// print_img(window, "./xpm/kawai_wall.xpm", 0, 64);
	// print_img(window, "./xpm/piece.xpm", 0, 128);
	//position dans l'ecran
	//AFFICHER PLUSIEURS IMAGES
	/**/
	int i = 0;
	int j;
	// printf("lenline = %d\n", data.lenline);
	//
	// // print_img(window, "./game/flower.xpm", 0, 0);
	while (i < data->nb_line)
	{
		print_img(window, "./xpm/kawai_wall.xpm", 0, i*32);
		if (i == 0 || i == data->nb_line - 1)
		{
			j = 1;
			while (j < data->len_line)
			{
				print_img(window, "./xpm/kawai_wall.xpm", j*32, 0);
				j++;
			}
		}
		i++;
	}
	// system("leaks so_long");
	design_game(&window);
	mlx_hook(window.win_ptr, 2, 0, ft_keyboard_event, &window);
	mlx_hook(window.win_ptr, 17, 0, ft_mouse_event, &window);
	mlx_loop(window.mlx_ptr);
}
