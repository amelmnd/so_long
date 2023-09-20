/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:40:02 by amennad           #+#    #+#             */
/*   Updated: 2023/09/20 12:49:02 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_position(t_data *data, char position)
{
	if (position == '0')
	{
		printf("Ok\n");
		return (1);
	}
	else if (position == 'C')
	{
		printf("item\n");
		data->nb_collected++;
		return (1);
	}
	else if (position == '1')
	{
		printf("mur\n");
		return (0);
	}
	else if (position == 'E' && data->nb_collected != data->nb_item)
	{
		printf("Ok\n");
		return (1);
	}
	else if (position == 'E' && data->nb_collected == data->nb_item)
	{
		printf("exit\n");
		return (-1);
	}
	return (0);
}

void	ft_move_up(t_data *data)
{
	char	position;

	position = data->map[data->player_line - 1][data->player_col];
	if (check_position(data, position) == 0)
		return ;
	else if (check_position(data, position) == 1)
	{
		data->map[data->player_line - 1][data->player_col] = 'P';
		data->map[data->player_line][data->player_col] = '0';
		data->player_line--;
		print_map(data->map);
	}
	else if (check_position(data, position) == -1)
	{
		printf("You win !\n");
		exit(EXIT_SUCCESS);
	}
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
		print_map(data->map);
	}
	else if (check_position(data, position) == -1)
	{
		printf("You win !\n");
		exit(EXIT_SUCCESS);
	}
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
		print_map(data->map);
	}
	else if (check_position(data, position) == -1)
	{
		printf("You win !\n");
		exit(EXIT_SUCCESS);
	}
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
		print_map(data->map);
	}
	else if (check_position(data, position) == -1)
	{
		printf("You win !\n");
		exit(EXIT_SUCCESS);
	}
}
