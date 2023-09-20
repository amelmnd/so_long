#ifndef MLX_SO_LONG_H
# define MLX_SO_LONG_H

# include "all_struct.h"
# include "mlx_so_long.h"
# include "so_long.h"

// prototypes
t_window	new_game(t_data *data, int w, int h, char *str);
t_image		new_img(int w, int h, t_window window);
void		put_pixel_img(t_image img, int x, int y, int color);

void		manage_game(t_data *data);
int			ft_mouse_event(t_window *window);
int			ft_keyboard_event(int keycode, t_window *window);
void		print_img(t_window window, char *path, int x, int y);
void		print_pixel(t_window window, int image_width, int image_heigth);

#endif
