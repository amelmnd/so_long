/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:11:10 by amennad           #+#    #+#             */
/*   Updated: 2023/09/21 10:57:32 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

int	search_element(char **map, int *col, int *row, char cara)
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
				*col = i;
				*row = j;
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

void	create_temp_array(t_data *data, char **temp, int i)
{
	int	j;

	j = 0;
	temp[i] = (char *)calloc(data->len_line + 1, sizeof(char));
	while (j < data->len_line)
	{
		temp[i][j] = data->map[i][j];
		j++;
	}
}

void	valid_map(t_data *data)
{
	int		col;
	int		row;
	int		i;
	int		search;
	char	**temp;

	col = 0;
	row = 0;
	i = -1;
	temp = (char **)calloc(data->nb_line + 1, sizeof(char *));
	while (++i < data->nb_line)
		create_temp_array(data, temp, i);
	search = search_element(data->map, &col, &row, 'P');
	data->player_col = row;
	data->player_line = col;
	if (search == 0)
		ft_exit_free(-1, data->map, NULL, "map is not valid");
	flood_fill_call(temp, &search, &col, &row);
	check_map_isvalid(temp);
	ft_free_2d_array(temp);
}
