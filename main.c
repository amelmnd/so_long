/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:25:04 by amennad           #+#    #+#             */
/*   Updated: 2023/09/16 19:28:42 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft/libft.h"
#include "so_long.h"

int	check_file_name(char *file_name)
{
	char	*dotte_exist;

	dotte_exist = 0;
	dotte_exist = ft_strchr(file_name, '.');
	if (!dotte_exist)
		ft_exit_free(-1, NULL, dotte_exist, "bad file");
	else if (dotte_exist[1] != 'b' && dotte_exist[2] != 'e'
			&& dotte_exist[3] != 'r' && dotte_exist[4] != '\0')
	{
		ft_exit_free(-1, NULL, dotte_exist, "bad file");
	}
	return (1);
}

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
