/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/09/15 16:34:13 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "get_next_line.h"
#include "so_long.h"

void	free_elements(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*read_fd(char *temp, int fd)
{
	char	buffer[2];
	int		nb_read;

	nb_read = 1;
	buffer[0] = '\0';
	while (nb_read && line_chr(buffer) == -1)
	{
		nb_read = read(fd, buffer, 1);
		if (nb_read == -1 || (!nb_read && !temp))
		{
			free_elements(&temp);
			return (0);
		}
		buffer[nb_read] = '\0';
		if (temp)
			temp = ft_strjoin_gnl(temp, buffer);
		else
			temp = ft_strdup(buffer);
	}
	return (temp);
}

char	*gen_line(int fd, char *temp, char **storage)
{
	char	*line;

	line = read_fd(temp, fd);
	if (!line)
		return (0);
	temp = ft_strdup(line);
	free_elements(&line);
	if (temp && (line_chr(temp) != -1))
	{
		line = ft_substr(temp, 0, line_chr(temp) + 1);
		if (ft_strlen_gnl(line) != ft_strlen_gnl(temp))
			*storage = ft_substr(temp, line_chr(temp) + 1, ft_strlen_gnl(temp));
		free_elements(&temp);
		return (line);
	}
	if (temp)
		return (temp);
	free_elements(&temp);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*temp;

	storage = NULL;
	line = NULL;
	temp = NULL;
	if (!storage)
	{
		return (gen_line(fd, temp, &storage));
	}
	if (line_chr(storage) != -1)
	{
		line = ft_substr(storage, 0, line_chr(storage) + 1);
		temp = ft_substr(storage, line_chr(storage) + 1,
				ft_strlen_gnl(storage));
		free_elements(&storage);
		storage = ft_strdup(temp);
		free_elements(&temp);
		return (line);
	}
	temp = ft_strdup(storage);
	free_elements(&storage);
	return (gen_line(fd, temp, &storage));
}
