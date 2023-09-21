/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:25:04 by amennad           #+#    #+#             */
/*   Updated: 2023/09/21 12:35:47 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft/libft.h"
#include "so_long.h"

void	init_data(t_data *data)
{
	data->len_line = 0;
	data->nb_line = 0;
	data->nb_move = 0;
	data->nb_item = 0;
	data->nb_collected = 0;
	data->player_line = 0;
	data->player_col = 0;
	data->not_finish = 0;
	data->nb_move = 0;


}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	init_data(&data);
	check_file_name(av[1]);
	ft_parsing(av[1], &data);
	printf("main ********\n");
	print_map(data.map);
	// system("leaks so_long");
	ft_game(&data);
	return (0);
}
