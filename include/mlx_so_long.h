#ifndef MLX_SO_LONG_H
# define MLX_SO_LONG_H

# include "all_struct.h"
# include "mlx_so_long.h"
# include "so_long.h"

// structs
// typedef struct s_window
// {
// 	void		*mlx_ptr;
// 	void		*win_ptr;
// 	int			height;
// 	int			width;
// }				t_window;

// typedef struct s_image
// {
// 	t_window	win;
// 	void		*img_ptr;
// 	int			*data;
// 	char		*addr;
// 	int			h;
// 	int			w;
// 	int			size_l;
// 	int			bpp;
// 	int			endian;
// 	int			line_len;
// }				t_image;

// typedef struct s_data
// {
// 	int			len_line;
// 	int			nb_line;
// 	int			nb_move;
// 	int			nb_item;
// 	int			nb_collected;
// 	int			player_x;
// 	int			player_y;
// 	char		**map;
// }				t_data;

// prototypes
t_window	new_game(int w, int h, char *str);
t_image		new_img(int w, int h, t_window window);
void		put_pixel_img(t_image img, int x, int y, int color);

void		manage_game(t_data *data);
int			ft_mouse_event(t_window *window);
int			ft_keyboard_event(int keycode, t_window *window);
void		print_img(t_window window, char *path, int x, int y);
void		print_pixel(t_window window, int image_width, int image_heigth);

#endif
