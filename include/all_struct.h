#ifndef STRUCT_SO_LONG_H
# define STRUCT_SO_LONG_H

// structs

typedef struct s_data
{
	int			len_line;
	int			nb_line;
	int			nb_move;
	int			nb_item;
	int			nb_collected;
	int			player_x;
	int			player_y;
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



#endif
