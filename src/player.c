/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:32:26 by dda-cunh          #+#    #+#             */
/*   Updated: 2024/11/16 12:15:15 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_point_2d	object_coords(char object, t_map *map)
{
	int	x;
	int	y;

	if (!map || !map->lines)
		return ((t_point_2d){-1, -1});
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			if (map->lines[y][x] == object)
				return ((t_point_2d){x, y});
	}
	return ((t_point_2d){-1, -1});
}

static void	do_move(t_prog *program, t_point_2d old_coords, t_event dir)
{
	static int	exit_updated = 0;
	t_point_2d	exitcoords;
	t_point_2d	p_coords;

	p_coords = program->map.player_coords;
	if (program->map.underp != CELL_EXIT)
		put_object(CELL_FLOOR, program, E_NONE, old_coords);
	else
		put_object(CELL_EXIT, program, E_NONE, old_coords);
	program->map.lines[old_coords.y][old_coords.x] = program->map.underp;
	if (program->map.lines[p_coords.y][p_coords.x] == CELL_COLLECTABLE)
	{
		program->map.lines[p_coords.y][p_coords.x] = CELL_FLOOR;
		program->map.n_coll--;
	}
	program->map.underp = program->map.lines[p_coords.y][p_coords.x];
	program->map.lines[p_coords.y][p_coords.x] = CELL_PLAYER;
	if (!exit_updated && program->map.n_coll == 0)
	{
		exitcoords = object_coords(CELL_EXIT, &(program->map));
		if (exitcoords.x != -1)
		{
			program->map.lines[exitcoords.y][exitcoords.x] = CELL_EXIT_OPEN;
			put_object(CELL_EXIT_OPEN, program, E_NONE, exitcoords);
		}
		exit_updated = 1;
	}
	program->map.pmoves++;
	put_object(CELL_PLAYER, program, dir, p_coords);
	if (program->map.underp == CELL_EXIT_OPEN)
		killprogram(0, program);
	footer(program);
}

void	try_move(t_event direction, t_prog *program)
{
	t_point_2d	old_coords;
	t_point_2d	coords;

	coords = program->map.player_coords;
	old_coords = coords;
	if (direction == E_PLAYER_UP)
		coords.y -= 1;
	else if (direction == E_PLAYER_LEFT)
		coords.x -= 1;
	else if (direction == E_PLAYER_DOWN)
		coords.y += 1;
	else if (direction == E_PLAYER_RIGHT)
		coords.x += 1;
	else
		return ;
	if (program->map.lines[coords.y][coords.x] == CELL_WALL)
		return ;
	program->map.player_coords = coords;
	do_move(program, old_coords, direction);
}
