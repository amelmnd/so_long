/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_so_long.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:53:03 by amennad           #+#    #+#             */
/*   Updated: 2023/09/20 15:45:36 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_SO_LONG_H
# define MLX_SO_LONG_H

# include "all_struct.h"
# include "mlx_so_long.h"
# include "so_long.h"

// prototypes
t_window	new_game(t_data *data, int w, int h, char *str);
t_image		new_img(int w, int h, t_window window);
void		put_pixel_img(t_image img, int x, int y, int color);

void		ft_game(t_data *data);
int			ft_mouse_event(t_window *window);
int			ft_keyboard_event(int keycode, t_window *window);
void		print_img(t_window window, char *path, int x, int y);
void		print_pixel(t_window window, int image_width, int image_heigth);

// game

void		ft_move_up(t_data *data);
void		ft_move_down(t_data *data);
void		ft_move_left(t_data *data);
void		ft_move_right(t_data *data);
int			check_position(t_data *data, char position);
void		collect_item(char position, t_data *data);
void		is_finished(t_data *data, char position);

#endif
