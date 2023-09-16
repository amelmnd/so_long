/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:57:08 by amennad           #+#    #+#             */
/*   Updated: 2023/09/16 11:36:50 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

void	check_first_last_line(int i, int j, char **map, int nb_line)
{
	if ((i == 0 && map[i][j] != '1') || (i == (nb_line - 1)
			&& map[i][j] != '1'))
		ft_exit_free(-1, NULL, "map not closed");
}

void	check_cara(char c, int *perso, int *end, int *item)
{
	if (c == 'P' && *perso == 0)
		*perso += 1;
	else if (c == 'P' && *perso == 1)
		ft_exit_free(-1, NULL, "too many perso");
	else if (c == 'E' && *end == 0)
		*end += 1;
	else if (c == 'E' && *end == 1)
		ft_exit_free(-1, NULL, "too many end");
	else if (c == 'C')
		*item += 1;
	else if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		ft_exit_free(-1, NULL, "invalid character");
}

void	check_map(char **map, int nb_line, int len_line)
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
	while (i < nb_line)
	{
		j = 0;
		if (map[i][0] != '1' || map[i][len_line - 1] != '1')
			ft_exit_free(-1, NULL, "map not closed");
		while (j < len_line)
		{
			check_first_last_line(i, j, map, nb_line);
			check_cara(map[i][j], &perso, &end, &item);
			j++;
		}
		i++;
	}
	if (perso == 0 || end == 0 || item == 0)
		ft_exit_free(-1, NULL, "missing element");
}
