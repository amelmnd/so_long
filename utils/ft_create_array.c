/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:33:41 by amennad           #+#    #+#             */
/*   Updated: 2023/09/15 15:55:00 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

char	*create_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	return (line);
}

void	ft_file_length(int fd, int *len_line, int *nb_line)
{
	int		i;
	char	*line;

	i = 0;
	line = create_line(fd);
	if (!line)
		ft_exit(-1, NULL);
	*len_line = ft_strlen(line);
	while (line)
	{
		//TODO check longeur de chaque ligne pour verifier si c'est cohearant sinon exit error message
		i++;
		free(line);
		line = create_line(fd);
	}
	*nb_line = i;
}
//TODO gerer les leaks en recuperant la ligne et en remplissant l'element de tableau

char	**ft_create_multi_array(int fd2, int nb_line, char **map)
{
	int	y;

	y = 0;
	map = (char **)malloc(nb_line * sizeof(char *));
	while (y < nb_line)
	{
		map[y] = create_line(fd2);
		printf("map[%d] = %s\n", y, map[y]);
		y++;
	}
	return (map);
}
