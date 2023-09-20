/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:57:08 by amennad           #+#    #+#             */
/*   Updated: 2023/09/19 17:22:42 by amennad          ###   ########.fr       */
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

void	check_cara(char c, int *perso, int *end, int *item)
{
	if (c == 'P' && *perso == 0)
		*perso += 1;
	else if (c == 'P' && *perso == 1)
		ft_exit_free(-1, NULL, NULL, "too many perso");
	else if (c == 'E' && *end == 0)
		*end += 1;
	else if (c == 'E' && *end == 1)
		ft_exit_free(-1, NULL, NULL, "too many end");
	else if (c == 'C')
		*item += 1;
	else if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		ft_exit_free(-1, NULL, NULL, "invalid character");
}

void	check_map(t_data *data)
{
	int	i;
	int	j;
	int	perso;
	int	end;
	int	item;

	i = 0;
	perso = 0;
	end = 0;
	item = 0;
	while (i < data->nb_line)
	{
		j = 0;
		if (data->map[i][0] != '1' || data->map[i][data->len_line - 1] != '1')
			ft_exit_free(-1, data->map, NULL, "map not closed");
		while (j < data->len_line)
		{
			check_first_last_line(i, j, data->map, data->nb_line);
			check_cara(data->map[i][j], &perso, &end, &item);
			j++;
		}
		i++;
	}
	if (perso == 0 || end == 0 || item == 0)
		ft_exit_free(-1, NULL, NULL, "missing element");
	data->nb_item = item;
}
