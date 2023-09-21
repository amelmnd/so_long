/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:43:44 by amennad           #+#    #+#             */
/*   Updated: 2023/09/21 10:50:24 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h" //for open
# include "../mlx/mlx.h"
# include "all_struct.h"
# include "mlx_so_long.h"
# include "so_long.h"
// selon les besoins du projet, ajouter les includes nécessaires
# include <errno.h>  //for errno
# include <fcntl.h>  //for open
# include <stdio.h>  //for printf
# include <stdlib.h> //for malloc
# include <unistd.h> //for write

// structure

//for dev
void	print_map(char **array);

// utils
char	*get_next_line(int fd);
void	ft_free_2d_array(char **array);
void	ft_exit_free(int status, char **tab, char *str, char *message);
char	*create_line(int fd);
void	ft_create_multi_array(int fd2, t_data *data);

// parsing
void	ft_parsing(char *file, t_data *data);
int		check_file_name(char *file_name);
void	ft_file_length(int fd, t_data *data);
void	check_map(t_data *data);
void	valid_map(t_data *data);
void	ft_flood_fill(char **temp, int x, int y);
void	flood_fill_call(char **temp, int *search, int *x, int *y);
int		search_element(char **map, int *col, int *row, char cara);

#endif
