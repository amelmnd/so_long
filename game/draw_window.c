/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:37:17 by amennad           #+#    #+#             */
/*   Updated: 2023/09/20 13:21:04 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>

void	print_img(t_window window, char *path, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(window.mlx_ptr, path, &img_width, &img_height);
	if (!img)
		printf("Error2\n");
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, img, x, y);
}

void	print_pixel(t_window window, int image_width, int image_heigth)
{
	t_image	image;
	int		count_width;
	int		count_heigth;

	count_width = 0;
	image = new_img(image_width, image_heigth, window);
	image.data = (int *)mlx_get_data_addr(image.img_ptr, &image.bpp,
			&image.size_l, &image.endian);
	while (count_width < image_width - 1)
	{
		count_heigth = 0;
		while (count_heigth < image_heigth - 1)
		{
			if (count_width % 2)
				image.data[count_heigth * image_width + count_width] = 0xFFFFFF;
			else
				image.data[count_heigth * image_width + count_width] = 0x32A852;
			count_heigth++;
		}
		count_width++;
	}
	mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr,
		image.img_ptr, 0, 0);
}
