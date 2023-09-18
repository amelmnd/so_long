/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:44:11 by amennad           #+#    #+#             */
/*   Updated: 2023/09/18 19:19:33 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>

// int	main(void)
// {
// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "my_mlx");
// 	if (!win)
// 		printf("Error1\n");
// 	img = mlx_xpm_file_to_image(mlx, "./textures/wall_n.xpm", &img_width,
// 			&img_height);
// 	if (!img)
// 		printf("Error2\n");
// 	mlx_put_image_to_window(mlx, win, img, 50, 50);
// 	mlx_loop(mlx);
// 	return (0);
// }

void	manage_game(char **map, int nb_line, int len_line)
{
	t_window window;
	// t_img image;
	int img_width;
	int img_height;
	void *img;

	window = new_game((len_line * 100), (nb_line * 100), "so_long");
	if (!window.mlx_ptr || !window.win_ptr)
		ft_exit_free(1, map, NULL, "Error\nmlx_init() failed\n");

	//AFFICHER DES PIXELS
	// image = new_img((len_line * 100), (nb_line * 100), window);
	// put_pixel_img(image, 250, 100, 0x00FFFFFF);
	// mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr,
	// image.img_ptr,0, 0);

	//AFFICHER UNE IMAGE
	img = mlx_xpm_file_to_image(window.mlx_ptr, "./game/flower.xpm", &img_width,
			&img_height);
	if (!img)
		printf("Error2\n");
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, img, ((len_line
					* 100) / 3), ((nb_line * 100) / 2));
	// mlx_loop(mlx);
	mlx_hook(window.win_ptr, 2, 0, ft_keyboard_event, &window);
	mlx_hook(window.win_ptr, 17, 0, ft_mouse_event, &window);
	mlx_loop(window.mlx_ptr);
}