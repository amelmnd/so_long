/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:05:38 by amennad           #+#    #+#             */
/*   Updated: 2023/09/19 17:23:51 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

void	ft_parsing(char *file, t_data *data)
{
	int	fd1;
	int	fd2;

	fd1 = open(file, O_RDONLY);
	fd2 = open(file, O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		ft_exit_free(-1, NULL, NULL, "open");
	ft_file_length(fd1, data);
	close(fd1);
	data->map = (char **)malloc(sizeof(char *) * (data->nb_line + 1));
	ft_create_multi_array(fd2, data);
	check_map(data);
	valid_map(data);
}
