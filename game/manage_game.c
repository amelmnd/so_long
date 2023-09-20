/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:24:27 by amennad           #+#    #+#             */
/*   Updated: 2023/09/20 15:42:16 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TODO GERER LA COLLECTE DES ITEMS

void	collect_item(char position, t_data *data)
{
	if (position == 'C')
	{
		data->nb_collected += 1;
	}
};

// TODO GERER LA SORTIE
//pour la sortie retransformer en E au changement de case voir comment faire ca peut etre avec un statue sorti qui change quand on a tout collecte du coup on a besoin de la position de la sortie mais pas de place dans la fonction a verifier sinon juste un status qui changer dans le structure au moment du passage sur la sortie check satatus sortie dans la fonction de deplacement
int	check_position(t_data *data, char position)
{
	printf("item\n");
	printf("---before start move----\n");
	printf("data->nb_collected = %d\n", data->nb_collected);
	printf("data->nb_item = %d\n", data->nb_item);
	if (position == '0')
		return (1);
	else if (position == 'C')
		return (1);
	else if (position == '1')
	{
		printf("mur\n");
		return (0);
	}
	else if (position == 'E' && data->nb_collected != data->nb_item)
	{
		printf("not finish\n");
		return (1);
	}
	else if (position == 'E' && data->nb_collected == data->nb_item)
	{
		printf("exit\n");
		return (-1);
	}
	return (0);
}