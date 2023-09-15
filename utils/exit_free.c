/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:09:26 by amennad           #+#    #+#             */
/*   Updated: 2023/09/15 16:54:25 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

void	ft_exit_free(int status, char *tab, char *message)
{
	if (status == 0)
	{
		ft_free_str(&tab);
		exit(EXIT_SUCCESS);
	}
	else if (status == -1)
	{
		ft_free_str(&tab);
		ft_printf("Error : %s\n", message);
		if (errno)
			perror(message);
		exit(EXIT_FAILURE);
	}
}
