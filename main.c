/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:25:04 by amennad           #+#    #+#             */
/*   Updated: 2023/09/20 15:42:31 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft/libft.h"
#include "so_long.h"

void	init_data(t_data *data)
{
	data->len_line = 0;
	data->nb_line = 0;
	data->nb_move = 0;
	data->nb_item = 0;
	data->nb_collected = 0;
	data->player_line = 0;
	data->player_col = 0;
}

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }			t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

int	main(int ac, char **av)
{
	t_data	data;

	// int		nb_line;
	// int		len_line;
	// char	**map;
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;
	if (ac != 2)
		return (0);
	init_data(&data);
	printf("nb_line = %d\n", data.nb_line);
	printf("len_line = %d\n", data.len_line);
	printf("nb_move = %d\n", data.nb_move);
	printf("nb_item = %d\n", data.nb_item);
	printf("nb_collected = %d\n", data.nb_collected);
	printf("player_line = %d\n", data.player_line);
	printf("player_col = %d\n", data.player_col);
	check_file_name(av[1]); //✅
	ft_parsing(av[1], &data);
	print_map(data.map);
	printf("nb_line = %d\n", data.nb_line);
	printf("len_line = %d\n", data.len_line);
	printf("nb_move = %d\n", data.nb_move);
	printf("nb_item = %d\n", data.nb_item);
	printf("nb_collected = %d\n", data.nb_collected);
	printf("player_line = %d\n", data.player_line);
	printf("player_col = %d\n", data.player_col);
	// system("leaks so_long");
	ft_game(&data);
	// check_file_name(av[1]);
	// map = ft_parsing(av[1], map, &nb_line, &len_line);
	// printf("main ********\n");
	// print_map(map);
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 52, 52, 0x00FF4566);
	// my_mlx_pixel_put(&img, 9, 9, 0x00FF4566);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
	// printf("mlx_win : %p\n", mlx_win);
	// ft_free_2d_array(map);
	return (0);
}
// #include "./mlx/mlx.h"
// #include <stdio.h>

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
