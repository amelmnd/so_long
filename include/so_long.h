/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:43:44 by amennad           #+#    #+#             */
/*   Updated: 2023/09/15 15:50:46 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h" //for open
// selon les besoins du projet, ajouter les includes nécessaires
# include <fcntl.h>  //for open
# include <stdio.h>  //for printf
# include <stdlib.h> //for malloc
# include <unistd.h> //for write

// utils
char	*get_next_line(int fd);
void	ft_exit(int status, char *tab);
char	*create_line(int fd);
char	**ft_create_multi_array(int fd2, int nb_line, char **map);
void	ft_file_length(int fd, int *len_line, int *nb_line);

#endif