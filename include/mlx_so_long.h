#ifndef MLX_SO_LONG_H
# define MLX_SO_LONG_H

// structs
typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
}				t_window;

typedef struct s_img
{
	t_window	win;
	void		*img_ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

// prototypes
t_window		new_game(int w, int h, char *str);
t_img			new_img(int w, int h, t_window window);
void			put_pixel_img(t_img img, int x, int y, int color);

void			manage_game(char **map, int nb_line, int len_line);
int				ft_mouse_event(t_window *window);
int				ft_keyboard_event(int keycode, t_window *window);

#endif
