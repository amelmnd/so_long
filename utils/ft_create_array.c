/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:33:41 by amennad           #+#    #+#             */
/*   Updated: 2023/09/19 17:20:59 by amennad          ###   ########.fr       */
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

void	ft_file_length(int fd, t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	line = create_line(fd);
	if (!line || ft_strline(line) < 3)
		ft_exit_free(-1, NULL, NULL, "bad map");
	data->len_line = ft_strline(line);
	while (line)
	{
		if (ft_strline(line) != data->len_line)
		{
			ft_exit_free(-1, NULL, line, "not good map");
		}
		i++;
		free(line);
		line = create_line(fd);
	}
	data->nb_line = i;
}

void	ft_create_multi_array(int fd2, t_data *data)
{
	int	y;

	y = 0;
	while (y < data->nb_line)
	{
		data->map[y] = create_line(fd2);
		y++;
	}
	data->map[y] = NULL;
}
