/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:09:26 by amennad           #+#    #+#             */
/*   Updated: 2023/09/16 16:52:13 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

void	ft_free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_free_str(&array[i]);
		i++;
	}
	free(array);
}

void	ft_exit_free(int status, char **tab, char *str, char *message)
{
	if (status == 0)
	{
		if (tab)
			ft_free_2d_array(tab);
		if (str)
			ft_free_str(&str);
		exit(EXIT_SUCCESS);
	}
	else if (status == -1)
	{
		if (tab)
			ft_free_2d_array(tab);
		if (str)
			ft_free_str(&str);
		ft_printf("Error : %s\n", message);
		if (errno)
			perror(message);
		exit(EXIT_FAILURE);
	}
}
