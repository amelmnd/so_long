/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:51:51 by amennad           #+#    #+#             */
/*   Updated: 2023/09/20 16:08:34 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SO_LONG_H
# define STRUCT_SO_LONG_H
//TODO PROBLEME DE NORME

// structs
typedef struct s_data
{
	int			len_line;
	int			nb_line;
	int			nb_move;
	int			nb_item;
	int			nb_collected;
	int			player_col;
	int			player_line;
	int			end_col;
	int			end_line;
	int			not_finish;
	char		**map;
}				t_data;

typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	t_data		*data;
}				t_window;

typedef struct s_image
{
	t_window	win;
	void		*img_ptr;
	int			*data;
	char		*addr;
	int			h;
	int			w;
	int			size_l;
	int			bpp;
	int			endian;
	int			line_len;
}				t_image;

typedef struct s_check
{
	int			perso;
	int			end;
	t_data		*data;
}				t_check;

#endif
