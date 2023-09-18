/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:30:59 by amennad           #+#    #+#             */
/*   Updated: 2023/09/18 11:15:54 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include "so_long.h"

int	check_file_name(char *file_name)
{
	char	*dotte_exist;

	dotte_exist = 0;
	dotte_exist = ft_strchr(file_name, '.');
	if (!dotte_exist)
		ft_exit_free(-1, NULL, dotte_exist, "bad file");
	else if (dotte_exist[1] != 'b' && dotte_exist[2] != 'e'
		&& dotte_exist[3] != 'r' && dotte_exist[4] != '\0')
	{
		ft_exit_free(-1, NULL, dotte_exist, "bad file");
	}
	return (1);
}
