/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:25:04 by amennad           #+#    #+#             */
/*   Updated: 2023/09/19 17:37:43 by amennad          ###   ########.fr       */
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
	data->player_x = 0;
	data->player_y = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	init_data(&data);
	printf("nb_line = %d\n", data.nb_line);
	printf("len_line = %d\n", data.len_line);
	printf("nb_move = %d\n", data.nb_move);
	printf("nb_item = %d\n", data.nb_item);
	printf("nb_collected = %d\n", data.nb_collected);
	printf("player_x = %d\n", data.player_x);
	printf("player_y = %d\n", data.player_y);
	check_file_name(av[1]); //✅
	ft_parsing(av[1], &data);
	print_map(data.map);
	printf("nb_line = %d\n", data.nb_line);
	printf("len_line = %d\n", data.len_line);
	printf("nb_move = %d\n", data.nb_move);
	printf("nb_item = %d\n", data.nb_item);
	printf("nb_collected = %d\n", data.nb_collected);
	printf("player_x = %d\n", data.player_x);
	printf("player_y = %d\n", data.player_y);
	manage_game(&data);
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
