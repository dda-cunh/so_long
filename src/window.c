/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:12:04 by dda-cunh          #+#    #+#             */
/*   Updated: 2024/11/16 11:30:41 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*get_path(char object, int event)
{
	if (object == CELL_WALL)
		return ("img/wall.xpm");
	else if (object == CELL_FLOOR)
		return ("img/floor.xpm");
	else if (object == CELL_PLAYER)
	{
		if (!event || event == E_PLAYER_UP)
			return ("img/player_up.xpm");
		else if (event == E_PLAYER_LEFT)
			return ("img/player_left.xpm");
		else if (event == E_PLAYER_DOWN)
			return ("img/player_down.xpm");
		else if (event == E_PLAYER_RIGHT)
			return ("img/player_right.xpm");
	}
	else if (object == CELL_COLLECTABLE)
		return ("img/collectable.xpm");
	else if (object == CELL_EXIT)
		return ("img/closed_exit.xpm");
	else if (object == CELL_EXIT_OPEN)
		return ("img/open_exit.xpm");
	return (NULL);
}

void	put_object(char object, t_prog *p, int event, t_point_2d grid_coord)
{
	t_point_2d	pixel_coord;
	t_image		uimg;
	t_image		img;
	char		*path;

	pixel_coord = (t_point_2d){grid_coord.x * SQUARE_SIZE,
		grid_coord.y * SQUARE_SIZE};
	path = get_path(object, event);
	img.ptr = mlx_xpm_file_to_image(p->mlx_ptr, path, &img.w, &img.h);
	if (img.ptr)
	{
		if (object == CELL_PLAYER || object == CELL_COLLECTABLE)
		{
			uimg.ptr = mlx_xpm_file_to_image(p->mlx_ptr,
					get_path(p->map.underp, event), &uimg.w, &uimg.h);
			print_blend(p, img, uimg, pixel_coord);
			mlx_destroy_image(p->mlx_ptr, uimg.ptr);
		}
		else
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, img.ptr,
				pixel_coord.x, pixel_coord.y);
		mlx_destroy_image(p->mlx_ptr, img.ptr);
	}
}

void	footer(t_prog *program)
{
	t_image	img;
	int		x;
	int		y;
	char	*path;

	y = program->map.height * SQUARE_SIZE + 1;
	x = 0;
	while (x < program->map.width * SQUARE_SIZE)
	{
		if (x == 0)
			path = "img/footer_left.xpm";
		else if ((x + SQUARE_SIZE) >= program->map.width * SQUARE_SIZE)
			path = "img/footer_right.xpm";
		else
			path = "img/footer_mid.xpm";
		img.ptr = mlx_xpm_file_to_image(program->mlx_ptr, path,
				&img.w, &img.h);
		if (img.ptr)
		{
			mlx_put_image_to_window(program->mlx_ptr,
				program->win_ptr, img.ptr, x, y);
			mlx_destroy_image(program->mlx_ptr, img.ptr);
		}
		x += SQUARE_SIZE;
	}
	putstr_footer(program, y, 0xFFB81C);
}

void	render_map(t_prog *p)
{
	t_point_2d	pixel_coords;
	t_point_2d	grid_coords;

	pixel_coords = (t_point_2d){0, 0};
	grid_coords = (t_point_2d){0, 0};
	while (pixel_coords.y < p->map.height * SQUARE_SIZE)
	{
		grid_coords.x = 0;
		pixel_coords.x = 0;
		while (pixel_coords.x < p->map.width * SQUARE_SIZE)
		{
				put_object(p->map.lines[grid_coords.y][grid_coords.x], p, E_NONE,
					(t_point_2d){grid_coords.x, grid_coords.y});
			pixel_coords.x += SQUARE_SIZE;
			grid_coords.x++;
		}
		pixel_coords.y += SQUARE_SIZE;
		grid_coords.y++;
	}
	footer(p);
}
