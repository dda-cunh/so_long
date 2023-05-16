/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:12:04 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/16 18:37:03 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_prog	new_program(int w, int h, char *title)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_prog){mlx_ptr, mlx_new_window(mlx_ptr, w, h, title),
		w, h, (t_map){NULL, 0, 0, 0, 0}});
}

char	*get_path(char object, int event)
{
	if (object == '1')
		return ("img/wall.xpm");
	else if (object == '0')
		return ("img/floor.xpm");
	else if (object == 'P')
	{
		if (!event || event == 1)
			return ("img/player_up.xpm");
		else if (event == 2)
			return ("img/player_left.xpm");
		else if (event == 3)
			return ("img/player_down.xpm");
		else if (event == 4)
			return ("img/player_right.xpm");
	}
	else if (object == 'C')
		return ("img/collectable.xpm");
	else if (object == 'E')
		return ("img/closed_exit.xpm");
	else if (object == 'X')
		return ("img/open_exit.xpm");
	return (NULL);
}

void	put_object(char object, t_prog *p, int event, int *xy)
{
	char	*path;
	t_image	img;
	t_image	uimg;

	path = get_path(object, event);
	img.ptr = mlx_xpm_file_to_image(p->mlx_ptr, path, &img.w, &img.h);
	if (img.ptr)
	{
		if (object == 'P' || object == 'C')
		{
			if (object == 'P')
				uimg.ptr = mlx_xpm_file_to_image(p->mlx_ptr,
						get_path(p->map.underp, event), &uimg.w, &uimg.h);
			else
				uimg.ptr = mlx_xpm_file_to_image(p->mlx_ptr,
						get_path('0', event), &uimg.w, &uimg.h);
			print_blend(p, img, uimg, xy);
			mlx_destroy_image(p->mlx_ptr, uimg.ptr);
		}
		else
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, img.ptr,
				xy[0], xy[1]);
		mlx_destroy_image(p->mlx_ptr, img.ptr);
	}
}

static	void	footer(t_prog *program, int x, int y)
{
	t_image	img;
	char	*path;

	while (x < program->map.width * 32)
	{
		if (x == 0)
			path = "img/footer_left.xpm";
		else if ((x + 32) >= program->map.width * 32)
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
		x += 32;
	}
	putstr_footer(program, y, 0xFFB81C);
}

void	render_map(t_prog *program, int event)
{
	int		i;
	int		j;
	int		coords[2];

	coords[1] = 0;
	j = 0;
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
	footer(program, 0, coords[1]);
}
