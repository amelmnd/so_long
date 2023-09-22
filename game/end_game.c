/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:24:41 by amennad           #+#    #+#             */
/*   Updated: 2023/09/22 11:37:19 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loose_game(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	ft_printf("You loose !\n");
	exit(EXIT_SUCCESS);
}

void	win_game(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	ft_printf("You win !\n");
	exit(EXIT_SUCCESS);
}
