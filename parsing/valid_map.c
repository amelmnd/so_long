/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:11:10 by amennad           #+#    #+#             */
/*   Updated: 2023/09/19 17:26:21 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

void	ft_flood_fill(char **temp, int x, int y)
{
	if (temp[x][y] == '0' || temp[x][y] == 'C' || temp[x][y] == 'E')
		temp[x][y] = 'F';
}

int	search_element(char **map, int *x, int *y, char cara)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == cara && (map[i + 1][j] == '0' || map[i
					- 1][j] == '0' || map[i][j + 1] == '0' || map[i][j
					- 1] == '0' || map[i + 1][j] == 'C' || map[i - 1][j] == 'C'
					|| map[i][j + 1] == 'C' || map[i][j - 1] == 'C' || map[i
					+ 1][j] == 'E' || map[i - 1][j] == 'E' || map[i][j
					+ 1] == 'E' || map[i][j - 1] == 'E'))
			{
				*x = i;
				*y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	check_map_isvalid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				ft_exit_free(-1, map, NULL, "map is not valid");
			j++;
		}
		i++;
	}
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

void	valid_map(t_data *data)
{
	int		x;
	int		y;
	int		i;
	int		search;
	char	**temp;

	x = 0;
	y = 0;
	i = 0;
	temp = (char **)malloc(data->nb_line * sizeof(char *));
	while (i < data->nb_line)
	{
		temp[i] = (char *)malloc(data->len_line + 1);
		ft_strncpy(temp[i], data->map[i], data->len_line);
		i++;
	}
	search = search_element(data->map, &x, &y, 'P');
	data->player_x = x;
	data->player_y = y;
	if (search == 0)
		ft_exit_free(-1, data->map, NULL, "map is not valid");
	flood_fill_call(temp, &search, &x, &y);
	check_map_isvalid(temp);
	ft_free_2d_array(temp);
}
