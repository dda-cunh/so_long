/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:25:43 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/15 00:19:59 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_image	new_image(int w, int h, t_prog window)
{
	t_image	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

int	get_pixel_color(t_image image, int x, int y)
{
	char	*img_data;
	int		color;

	img_data = mlx_get_data_addr(image.img_ptr, &image.bpp,
			&image.line_len, &image.endian);
	color = *(int *)(img_data + (y * image.line_len + x * (image.bpp / 8)));
	return (color);
}
