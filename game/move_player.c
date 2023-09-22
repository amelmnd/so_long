/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:40:02 by amennad           #+#    #+#             */
/*   Updated: 2023/09/22 11:36:50 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_window *window, t_data *data, char *status)
{
	char	position;

	position = data->map[data->player_line - 1][data->player_col];
	if (position == 'A')
		loose_game(window);
	else if (check_position(data, position) == 0)
		return ;
	else if (check_position(data, position) == 1)
	{
		data->map[data->player_line - 1][data->player_col] = 'P';
		data->map[data->player_line][data->player_col] = '0';
		data->player_line--;
		collect_item(position, data);
		*status = 'u';
		data->nb_move++;
		ft_printf("%d\n", data->nb_move);
	}
	else if (check_position(data, position) == -1)
		win_game(window);
	if (data->end_line != data->player_line
		|| data->end_col != data->player_col)
		data->map[data->end_line][data->end_col] = 'E';
}

void	ft_move_down(t_window *window, t_data *data, char *status)
{
	char	position;

	position = data->map[data->player_line + 1][data->player_col];
	if (position == 'A')
		loose_game(window);
	if (check_position(data, position) == 0)
		return ;
	else if (check_position(data, position) == 1)
	{
		data->map[data->player_line + 1][data->player_col] = 'P';
		data->map[data->player_line][data->player_col] = '0';
		data->player_line++;
		collect_item(position, data);
		*status = 'd';
		data->nb_move++;
		ft_printf("%d\n", data->nb_move);
	}
	else if (check_position(data, position) == -1)
		win_game(window);
	if (data->end_line != data->player_line
		|| data->end_col != data->player_col)
		data->map[data->end_line][data->end_col] = 'E';
}

void	ft_move_left(t_window *window, t_data *data, char *status)
{
	char	position;

	position = data->map[data->player_line][data->player_col - 1];
	if (position == 'A')
		loose_game(window);
	if (check_position(data, position) == 0)
		return ;
	else if (check_position(data, position) == 1)
	{
		data->map[data->player_line][data->player_col - 1] = 'P';
		data->map[data->player_line][data->player_col] = '0';
		data->player_col--;
		collect_item(position, data);
		*status = 'l';
		data->nb_move++;
		ft_printf("%d\n", data->nb_move);
	}
	else if (check_position(data, position) == -1)
		win_game(window);
	if (data->end_line != data->player_line
		|| data->end_col != data->player_col)
		data->map[data->end_line][data->end_col] = 'E';
}

void	ft_move_right(t_window *window, t_data *data, char *status)
{
	char	position;

	position = data->map[data->player_line][data->player_col + 1];
	if (position == 'A')
		loose_game(window);
	if (check_position(data, position) == 0)
		return ;
	else if (check_position(data, position) == 1)
	{
		data->map[data->player_line][data->player_col + 1] = 'P';
		data->map[data->player_line][data->player_col] = '0';
		data->player_col++;
		collect_item(position, data);
		*status = 'r';
		data->nb_move++;
		ft_printf("%d\n", data->nb_move);
	}
	else if (check_position(data, position) == -1)
		win_game(window);
	if (data->end_line != data->player_line
		|| data->end_col != data->player_col)
		data->map[data->end_line][data->end_col] = 'E';
}
