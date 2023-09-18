/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:25:04 by amennad           #+#    #+#             */
/*   Updated: 2023/09/18 11:46:37 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft/libft.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	int		nb_line;
	int		len_line;
	char	**map;
	void	*mlx;
	void	*mlx_win;

	map = NULL;
	nb_line = 0;
	len_line = 0;
	if (ac != 2)
		return (0);
	check_file_name(av[1]);
	map = ft_parsing(av[1], map, &nb_line, &len_line);
	printf("main ********\n");
	print_map(map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	printf("mlx_win : %p\n", mlx_win);
	// ft_free_2d_array(map);
	// system("leaks so_long");
	// return (0);
}
