/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:05:38 by amennad           #+#    #+#             */
/*   Updated: 2023/09/18 11:04:15 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

char	**ft_parsing(char *file, char **map, int *nb_line, int *len_line)
{
	int	fd1;
	int	fd2;

	fd1 = open(file, O_RDONLY);
	fd2 = open(file, O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		ft_exit_free(-1, NULL, NULL, "open");
	ft_file_length(fd1, len_line, nb_line);
	close(fd1);
	map = (char **)malloc(sizeof(char *) * (*nb_line + 1));
	map = ft_create_multi_array(fd2, *nb_line, map);
	check_map(map, *nb_line, *len_line);
	valid_map(map, *nb_line, *len_line);
	return (map);
}
