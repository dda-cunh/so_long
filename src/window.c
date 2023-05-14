/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:12:04 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/14 18:35:34 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_prog	new_program(int w, int h, char *title)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_prog){mlx_ptr, mlx_new_window(mlx_ptr, w, h, title),
		w, h, (t_map){NULL, 0, 0}});
}

void	print_floor(t_prog *program)
{
	int		x;
	int		y;
	int		w;
	int		h;
	void	*img;

	y = 0;
	img = mlx_xpm_file_to_image(program->mlx_ptr,
			"img/floor.xpm", &w, &h);
	while (y < program->width)
	{
		x = 0;
		while (x < program->height)
		{
			mlx_put_image_to_window(program->mlx_ptr,
				program->win_ptr, img, y, x);
			x += 32;
		}
		y += 32;
	}
	mlx_destroy_image(program->mlx_ptr, img);
}
