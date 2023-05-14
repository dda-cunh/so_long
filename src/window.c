/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:12:04 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/15 00:41:31 by dda-cunh         ###   ########.fr       */
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

char	*get_path(char object, int event)
{
	if (object == '1')
		return ("img/wall.xpm");
	else if (object == 'P')
	{
		if (!event || event == 1)
			return ("img/player_up.xpm");
		else if (event == 2)
			return ("img/player_right.xpm");
		else if (event == 3)
			return ("img/player_down.xpm");
		else if (event == 4)
			return ("img/player_left.xpm");
	}
	else if (object == 'C')
		return ("img/collectable.xpm");
	else if (object == 'E')
	{
		if (event != 7)
			return ("img/closed_exit.xpm");
		else
			return ("img/open_exit.xpm");
	}
	return (NULL);
}

void	put_object(char object, t_prog *program, int event, int coords[])
{
	char	*path;
	t_image	img;

	path = get_path(object, event);
	if (!path)
		return ;
	img.img_ptr = mlx_xpm_file_to_image(program->mlx_ptr, path, &img.w, &img.h);
	if (img.img_ptr)
	{
		mlx_put_image_to_window(program->mlx_ptr,
			program->win_ptr, img.img_ptr, coords[0], coords[1]);
		mlx_destroy_image(program->mlx_ptr, img.img_ptr);
	}
}

int	render_map(t_prog *program, int event)
{
	int		i;
	int		j;
	int		coords[2];

	coords[1] = 0;
	j = 0;
	mlx_clear_window(program->mlx_ptr, program->win_ptr);
	print_floor(program);
	while (coords[1] < program->map.height * 32)
	{
		i = 0;
		coords[0] = 0;
		while (coords[0] < program->map.width * 32)
		{
			put_object(program->map.lines[j][i], program, event,
				(int []){coords[0], coords[1]});
			coords[0] += 32;
			i++;
		}
		j++;
		coords[1] += 32;
	}
	return (0);
}
