/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:25:04 by amennad           #+#    #+#             */
/*   Updated: 2023/09/18 11:09:52 by amennad          ###   ########.fr       */
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
	printf("main ********\n");
	print_map(map);
	ft_free_2d_array(map);
	// system("leaks so_long");
	return (0);
}
