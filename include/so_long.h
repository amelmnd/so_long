/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:43:44 by amennad           #+#    #+#             */
/*   Updated: 2023/09/18 15:22:00 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h" //for open
#include "../mlx/mlx.h"
#include "mlx_so_long.h"
// selon les besoins du projet, ajouter les includes nécessaires
# include <errno.h>  //for errno
# include <fcntl.h>  //for open
# include <stdio.h>  //for printf
# include <stdlib.h> //for malloc
# include <unistd.h> //for write

//for dev
void	print_map(char **array);

// utils
char	*get_next_line(int fd);
void	ft_free_2d_array(char **array);
void	ft_exit_free(int status, char **tab, char *str, char *message);
char	*create_line(int fd);
char	**ft_create_multi_array(int fd2, int nb_line, char **map);
void	ft_file_length(int fd, int *len_line, int *nb_line);
int		check_file_name(char *file_name);

// parsing
char	**ft_parsing(char *file, char **map, int *nb_line, int *len_line);
void	check_map(char **map, int nb_line, int len_line);
void	valid_map(char **map, int nb_line, int len_line);

#endif
