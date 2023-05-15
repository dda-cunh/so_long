/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:32:26 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/15 17:01:54 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	*object_coords(char object, char **map, int width, int height)
{
	int	x;
	int	y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			if (map[y][x] == object)
				return ((int []){x, y});
	}
	return (NULL);
}

static void	do_move(t_prog *program, int *new_coords, int *curr_coords, int dir)
{
	static int	done = 0;
	int			*exitcoords;

	if (program->map.lines[new_coords[1]][new_coords[0]] != 'E')
	{
		if (program->map.lines[new_coords[1]][new_coords[0]] == 'X')
			killprogram(0, program);
		program->map.lines[new_coords[1]][new_coords[0]] = 'P';
		program->map.lines[curr_coords[1]][curr_coords[0]] = '0';
	}
	program->map.pmoves++;
	if (!object_coords('C', program->map.lines, program->map.width,
			program->map.height) && !done)
	{
		exitcoords = object_coords('E', program->map.lines, program->map.width,
				program->map.height);
		program->map.lines[exitcoords[1]][exitcoords[0]] = 'X';
		done = 1;
	}
	render_map(program, dir);
}

void	try_move(int direction, t_prog *program)
{
	int	*curr_coords;
	int	*new_coords;

	curr_coords = object_coords('P', program->map.lines, program->map.width,
			program->map.height);
	if (direction == 1)
		new_coords = (int []){curr_coords[0], curr_coords[1] - 1};
	else if (direction == 2)
		new_coords = (int []){curr_coords[0] - 1, curr_coords[1]};
	else if (direction == 3)
		new_coords = (int []){curr_coords[0], curr_coords[1] + 1};
	else if (direction == 4)
		new_coords = (int []){curr_coords[0] + 1, curr_coords[1]};
	else
		return ;
	if (program->map.lines[new_coords[1]][new_coords[0]] == '1')
	{
		render_map(program, direction);
		return ;
	}
	do_move(program, new_coords, curr_coords, direction);
}
