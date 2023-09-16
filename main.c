/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:25:04 by amennad           #+#    #+#             */
/*   Updated: 2023/09/16 11:39:54 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft/libft.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	int		nb_line;
	int		len_line;
	char	**map;

	map = NULL;
	nb_line = 0;
	len_line = 0;
	if (ac != 2)
		return (0);
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[1], O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		ft_exit_free(-1, NULL, "open");
	ft_file_length(fd1, &len_line, &nb_line);
	// if (len_line == nb_line) // un carre est un rectangle
	// 	ft_exit_free(-1, NULL, "map is square");
	map = ft_create_multi_array(fd2, nb_line, map);
	print_map(map);
	check_map(map, nb_line, len_line);
	// system("leaks so_long");
	return (0);
}
