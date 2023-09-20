/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:40:02 by amennad           #+#    #+#             */
/*   Updated: 2023/09/20 17:26:45 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_data *data)
{
	char	position;

	position = data->map[data->player_line - 1][data->player_col];
	printf("position = %c\n", position);
	if (check_position(data, position) == 0)
		return ;
	else if (check_position(data, position) == 1)
	{
		data->map[data->player_line - 1][data->player_col] = 'P';
		data->map[data->player_line][data->player_col] = '0';
		data->player_line--;
		collect_item(position, data);
	}
	else if (check_position(data, position) == -1)
	{
		printf("You win !\n");
		exit(EXIT_SUCCESS);
	}
	if (data->end_line != data->player_line
		|| data->end_col != data->player_col)
		data->map[data->end_line][data->end_col] = 'E';
}

void	ft_move_down(t_data *data)
{
	char	position;

	position = data->map[data->player_line + 1][data->player_col];
	if (check_position(data, position) == 0)
		return ;
	else if (check_position(data, position) == 1)
	{
		data->map[data->player_line + 1][data->player_col] = 'P';
		data->map[data->player_line][data->player_col] = '0';
		data->player_line++;
		collect_item(position, data);
	}
	else if (check_position(data, position) == -1)
	{
		printf("You win !\n");
		exit(EXIT_SUCCESS);
	}
	if (data->end_line != data->player_line
		|| data->end_col != data->player_col)
		data->map[data->end_line][data->end_col] = 'E';
}

void	ft_move_left(t_data *data)
{
	char	position;

	position = data->map[data->player_line][data->player_col - 1];
	if (check_position(data, position) == 0)
		return ;
	else if (check_position(data, position) == 1)
	{
		data->map[data->player_line][data->player_col - 1] = 'P';
		data->map[data->player_line][data->player_col] = '0';
		data->player_col--;
		collect_item(position, data);
	}
	else if (check_position(data, position) == -1)
	{
		printf("You win !\n");
		exit(EXIT_SUCCESS);
	}
	if (data->end_line != data->player_line
		|| data->end_col != data->player_col)
		data->map[data->end_line][data->end_col] = 'E';
}

void	ft_move_right(t_data *data)
{
	char	position;

	position = data->map[data->player_line][data->player_col + 1];
	if (check_position(data, position) == 0)
		return ;
	else if (check_position(data, position) == 1)
	{
		data->map[data->player_line][data->player_col + 1] = 'P';
		data->map[data->player_line][data->player_col] = '0';
		data->player_col++;
		collect_item(position, data);
	}
	else if (check_position(data, position) == -1)
	{
		printf("You win !\n");
		exit(EXIT_SUCCESS);
	}
	if (data->end_line != data->player_line
		|| data->end_col != data->player_col)
		data->map[data->end_line][data->end_col] = 'E';
}
