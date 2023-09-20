/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:57:08 by amennad           #+#    #+#             */
/*   Updated: 2023/09/20 16:27:14 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

void	check_first_last_line(int i, int j, char **map, int nb_line)
{
	if ((i == 0 && map[i][j] != '1') || (i == (nb_line - 1)
			&& map[i][j] != '1'))
		ft_exit_free(-1, map, NULL, "map not closed");
}

void	check_cara(char c, t_check *check, int i, int j)
{
	if (c == 'P' && check->perso == 0)
		check->perso += 1;
	else if (c == 'P' && check->perso == 1)
		ft_exit_free(-1, NULL, NULL, "too many perso");
	else if (c == 'E' && check->end == 0)
	{
		check->end += 1;
		check->data->end_line = i;
		check->data->end_col = j;
	}
	else if (c == 'E' && check->end == 1)
		ft_exit_free(-1, NULL, NULL, "too many end");
	else if (c == 'C')
		check->data->nb_item += 1;
	else if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		ft_exit_free(-1, NULL, NULL, "invalid character");
}

void	check_map(t_data *data)
{
	int		i;
	int		j;
	t_check	check;

	i = -1;
	check.data = data;
	check.perso = 0;
	check.end = 0;
	while (++i < data->nb_line)
	{
		j = 0;
		if (data->map[i][0] != '1' || data->map[i][data->len_line - 1] != '1')
			ft_exit_free(-1, data->map, NULL, "map not closed");
		while (j < data->len_line)
		{
			check_first_last_line(i, j, data->map, data->nb_line);
			check_cara(data->map[i][j], &check, i, j);
			j++;
		}
	}
	if (check.perso == 0 || check.end == 0 || check.data->nb_item == 0)
		ft_exit_free(-1, NULL, NULL, "missing element");
}
