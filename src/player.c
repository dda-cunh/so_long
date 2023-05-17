/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:32:26 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/17 17:12:08 by dda-cunh         ###   ########.fr       */
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

static void	do_move(t_prog *program, int *curr_coords, int *new_coords, int dir)
{
	int			*exitcoords;

	program->map.lines[curr_coords[1]][curr_coords[0]] = program->map.underp;
	if (program->map.lines[new_coords[1]][new_coords[0]] == 'C')
		program->map.lines[new_coords[1]][new_coords[0]] = '0';
	program->map.underp = program->map.lines[new_coords[1]][new_coords[0]];
	program->map.lines[new_coords[1]][new_coords[0]] = 'P';
	if (!object_coords('C', program->map.lines, program->map.width,
			program->map.height))
	{
		exitcoords = object_coords('E', program->map.lines,
				program->map.width, program->map.height);
		if (exitcoords)
			program->map.lines[exitcoords[1]][exitcoords[0]] = 'X';
	}
	program->map.pmoves++;
	render_map(program, dir, 0);
	if (program->map.underp == 'X')
		killprogram(0, program);
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
		put_object('P', program, direction, (int []){curr_coords[0] * 32,
			curr_coords[1] * 32});
		return ;
	}
	do_move(program, curr_coords, new_coords, direction);
}
