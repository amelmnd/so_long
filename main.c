/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:25:04 by amennad           #+#    #+#             */
/*   Updated: 2023/09/18 18:50:50 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft/libft.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	int		nb_line;
	int		len_line;
	char	**map;

	map = NULL;
	nb_line = 0;
	len_line = 0;
	if (ac != 2)
		return (0);
	check_file_name(av[1]);
	map = ft_parsing(av[1], map, &nb_line, &len_line);
	manage_game(map, nb_line, len_line);
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
