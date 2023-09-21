/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:43:52 by amennad           #+#    #+#             */
/*   Updated: 2023/09/21 10:44:14 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

void	ft_flood_fill(char **temp, int x, int y)
{
	if (temp[x][y] == '0' || temp[x][y] == 'C' || temp[x][y] == 'E')
		temp[x][y] = 'F';
}

void	flood_fill_call(char **temp, int *search, int *x, int *y)
{
	while (*search == 1)
	{
		ft_flood_fill(temp, *x + 1, *y);
		ft_flood_fill(temp, *x - 1, *y);
		ft_flood_fill(temp, *x, *y + 1);
		ft_flood_fill(temp, *x, *y - 1);
		*search = search_element(temp, x, y, 'F');
	}
}
