/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:25:43 by dda-cunh          #+#    #+#             */
/*   Updated: 2024/11/16 12:26:57 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_image	new_image(int w, int h, t_prog window)
{
	t_image	image;

	image.win = window;
	image.ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

int	get_pixel_color(t_image image, int x, int y)
{
	char	*img_data;
	int		color;

	img_data = mlx_get_data_addr(image.ptr, &image.bpp,
			&image.line_len, &image.endian);
	color = *(int *)(img_data + (y * image.line_len + x * (image.bpp / 8)));
	return (color);
}
void	print_blend(t_prog *prog, t_image img1, t_image img2, t_point_2d pos)
{
	t_point_2d	start;
	t_point_2d	curr;
	int			color;

	start.x = pos.x;
	start.y = pos.y;
	curr.y = 0;
	while (pos.y < start.y + SQUARE_SIZE)
	{
		pos.x = start.x;
		curr.x = 0;
		while (pos.x < start.x + SQUARE_SIZE)
		{
			color = get_pixel_color(img1, curr.x, curr.y);
			if (color == 0x292323)
				mlx_pixel_put(prog->mlx_ptr, prog->win_ptr, pos.x, pos.y,
					get_pixel_color(img2, curr.x, curr.y));
			else
				mlx_pixel_put(prog->mlx_ptr, prog->win_ptr, pos.x, pos.y, color);
			curr.x++;
			pos.x++;
		}
		curr.y++;
		pos.y++;
	}
}
