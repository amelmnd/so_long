/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:33:41 by amennad           #+#    #+#             */
/*   Updated: 2023/09/15 17:37:08 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

int	ft_strline(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

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
		ft_exit_free(-1, NULL, "ft_file_length");
	*len_line = ft_strline(line);
	while (line)
	{
		if (ft_strline(line) != *len_line)
		{
			ft_exit_free(-1, line, "not good map");
		}
		i++;
		free(line);
		line = create_line(fd);
	}
	*nb_line = i;
}

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
