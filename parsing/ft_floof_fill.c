/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floof_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:11:10 by amennad           #+#    #+#             */
/*   Updated: 2023/09/16 11:27:32 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

void	search_perso(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	valid_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	search_perso(map, &x, &y);
	printf("x = %d, y = %d\n", x, y);
	// ft_flood_fill(map, x, y);
}

// void	ft_flood_fill(char **map, int x, int y)
// {
// 	char	**temp;

// 	temp = map;
// 	if (temp[x][y] == '1' || temp[x][y] == 'P')
// 		return ;
// 	if (temp[x][y] == '0')
// 		temp[x][y] = 'F';
// 	if (temp[x][y] == 'C')
// 		temp[x][y] = 'F';
// 	if (temp[x][y] == 'E')
// 		temp[x][y] = 'F';
// 	print_map(temp);
// 	// ft_flood_fill(temp, x + 1, y);
// 	// ft_flood_fill(temp, x - 1, y);
// 	// ft_flood_fill(temp, x, y + 1);
// 	// ft_flood_fill(temp, x, y - 1);
// }