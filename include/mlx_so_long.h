/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_so_long.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:53:03 by amennad           #+#    #+#             */
/*   Updated: 2023/09/22 11:34:33 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_SO_LONG_H
# define MLX_SO_LONG_H

# include "all_struct.h"
# include "mlx_so_long.h"
# include "so_long.h"

// init game
t_window	new_game(t_data *data, int tile_size, char *str);
void		ft_game(t_data *data);
int			ft_mouse_event(t_window *window);
int			ft_keyboard_event(int keycode, t_window *window);
void		print_img(t_window window, char *path, int x, int y);
void		design_game(t_window *window);

// game
void		ft_move_up(t_window *window, t_data *data, char *status);
void		ft_move_down(t_window *window, t_data *data, char *status);
void		ft_move_left(t_window *window, t_data *data, char *status);
void		ft_move_right(t_window *window, t_data *data, char *status);
int			check_position(t_data *data, char position);
void		collect_item(char position, t_data *data);
void		loose_game(t_window *window);
void		win_game(t_window *window);

#endif
