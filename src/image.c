/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:25:43 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/16 19:13:32 by dda-cunh         ###   ########.fr       */
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

void	print_blend(t_prog *p, t_image t, t_image u, int *coords)
{
	int	xystart[2];
	int	xy[2];
	int	c;

	xystart[0] = coords[0];
	xystart[1] = coords[1];
	xy[1] = 0;
	while (coords[1] < xystart[1] + 32)
	{
		coords[0] = xystart[0];
		xy[0] = 0;
		while (coords[0] < xystart[0] + 32)
		{
			c = get_pixel_color(t, xy[0], xy[1]);
			if (c == 0x292323)
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, coords[0], coords[1],
					get_pixel_color(u, xy[0], xy[1]));
			else
				mlx_pixel_put(p->mlx_ptr, p->win_ptr, coords[0], coords[1], c);
			xy[0]++;
			coords[0]++;
		}
		xy[1]++;
		coords[1]++;
	}
}

void	print_floor(t_prog *program)
{
	int	coords[2];

	coords[1] = 0;
	while (coords[1] < program->map.height * 32)
	{
		coords[0] = 0;
		while (coords[0] < program->map.width * 32)
		{
			put_object('0', program, 0, (int []){coords[0], coords[1]});
			coords[0] += 32;
		}
		coords[1] += 32;
	}
}
