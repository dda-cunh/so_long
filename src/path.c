/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:19:03 by dda-cunh          #+#    #+#             */
/*   Updated: 2024/11/16 11:47:25 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	n_collect_or_exit(char **map, int width, int height)
{
	int	x;
	int	y;
	int	c;

	c = 0;
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			if (map[y][x] == CELL_COLLECTABLE)
				c++;
			else if (map[y][x] == CELL_EXIT)
				c++;
		}
	}
	return (c);
}

static int	timber(char **map, char **copy, t_point_2d p_coords, int const dim[2])
{
	if (p_coords.x < 0 || p_coords.x >= dim[0] || p_coords.y < 0
		|| p_coords.y >= dim[1] || copy[p_coords.y][p_coords.x] == CELL_WALL)
		return (0);
	else
	{
		if (copy[p_coords.y][p_coords.x] == CELL_EXIT
			|| copy[p_coords.y][p_coords.x] == CELL_COLLECTABLE)
		{
			map[p_coords.y][p_coords.x] = CELL_FLOOR;
			return (1);
		}
		copy[p_coords.y][p_coords.x] = CELL_WALL;
	}
	return (timber(map, copy, (t_point_2d){p_coords.x + 1, p_coords.y}, dim)
			|| timber(map, copy, (t_point_2d){p_coords.x - 1, p_coords.y}, dim)
			|| timber(map, copy, (t_point_2d){p_coords.x, p_coords.y + 1}, dim)
			|| timber(map, copy, (t_point_2d){p_coords.x, p_coords.y - 1}, dim));
}

int	parse_path(t_map *map)
{
	char	**cp1;
	char	**cp2;
	int		n_coll_or_exit;

	cp1 = copy2d(map->lines, map->height);
	if (!cp1)
		return (0);
	n_coll_or_exit = n_collect_or_exit(map->lines, map->width, map->height);
	map->n_coll = n_coll_or_exit - 1;
	while (n_coll_or_exit > 0)
	{
		cp2 = copy2d(cp1, map->height);
		if (!cp2)
			break ;
		if (!timber(cp1, cp2, map->player_coords, (int []){map->width, map->height}))
		{
			free_2d(cp2);
			break ;
		}
		free_2d(cp2);
		n_coll_or_exit--;
	}
	free_2d(cp1);
	return (n_coll_or_exit == 0);
}
