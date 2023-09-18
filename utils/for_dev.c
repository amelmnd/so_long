/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_dev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:10:58 by amennad           #+#    #+#             */
/*   Updated: 2023/09/18 11:01:41 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"
#include <stdio.h>

void	blue(void)
{
	printf("\033[1;34m");
}

void	cyan(void)
{
	printf("\033[1;36m");
}

void	pink(void)
{
	printf("\033[1;35m");
}

void	red(void)
{
	printf("\033[1;31m");
}

void	yellow(void)
{
	printf("\033[1;33m");
}

void	green(void)
{
	printf("\033[1;32m");
}

void	reset(void)
{
	printf("\033[0m");
}

void	print_map(char **array)
{
	int	i;
	int	j;

	i = 0;
	if (!array)
	{
		printf("print_map: array is NULL\n");
		return ;
	}
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			blue();
			printf("| ");
			if (array[i][j] == '1')
				pink();
			else if (array[i][j] == '0')
				cyan();
			else if (array[i][j] == 'C')
				yellow();
			else if (array[i][j] == 'E')
				red();
			else if (array[i][j] == 'P')
				green();
			printf("%c ", array[i][j]);
			j++;
			reset();
		}
		printf("\n");
		i++;
	}
}
