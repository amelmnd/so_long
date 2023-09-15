/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:25:04 by amennad           #+#    #+#             */
/*   Updated: 2023/09/15 16:34:34 by amennad          ###   ########.fr       */
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
	if (ac != 2)
		return (0);
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[1], O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
	{
		perror("open");
		ft_exit(-1, NULL);
	}
	ft_file_length(fd1, &len_line, &nb_line);
	//TODO check si c'est un rectange ou non
	printf("nb_line = %d\n", nb_line);
	printf("len_line = %d\n", len_line);
	map = ft_create_multi_array(fd2, nb_line, map);
	system("leaks so_long");
	return (0);
}
