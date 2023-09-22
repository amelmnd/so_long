/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:24:27 by amennad           #+#    #+#             */
/*   Updated: 2023/09/21 19:14:55 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_item(char position, t_data *data)
{
	if (position == 'C')
	{
		data->nb_collected += 1;
		data->collected = 1;
	}
	if (data->nb_collected == data->nb_item)
	{
		data->not_finish = 0;
	}
}

void	is_finished(t_data *data, char position)
{
	if (data->not_finish == 1)
	{
		data->map[data->end_line][data->end_col] = 'E';
		data->not_finish = 0;
	}
	if (position == 'E' && data->nb_collected == data->nb_item)
	{
		ft_printf("You win !\n");
		exit(EXIT_SUCCESS);
	}
	else if (position == 'E' && data->nb_collected != data->nb_item)
	{
		data->not_finish = 1;
	}
}

int	check_position(t_data *data, char position)
{
	if (position == '0')
		return (1);
	else if (position == 'C')
		return (1);
	else if (position == '1')
	{
		return (0);
	}
	else if (position == 'E' && data->nb_collected != data->nb_item)
	{
		data->not_finish = 1;
		return (1);
	}
	else if (position == 'E' && data->nb_collected == data->nb_item)
	{
		return (-1);
	}
	return (0);
}
