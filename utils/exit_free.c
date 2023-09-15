/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:09:26 by amennad           #+#    #+#             */
/*   Updated: 2023/09/15 10:18:34 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

void	ft_exit(int status, char *tab)
{
	if (status == 0)
	{
		ft_free_str(&tab);
		exit(EXIT_SUCCESS);
	}
	else if (status == -1)
	{
		ft_free_str(&tab);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
