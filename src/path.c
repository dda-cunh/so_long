/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:19:03 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/17 15:46:42 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	timber(char **map, char **copy, int xyp[2], int dimensions[2]);

static int	n_collect(char **map, int width, int height)
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
			if (map[y][x] == 'C')
				c++;
			else if (map[y][x] == 'E')
				c++;
		}
	}
	return (c);
}

static int	timber(char **map, char **copy, int xyp[2], int dimensions[2])
{
	if (xyp[0] < 0 || xyp[0] >= dimensions[0] || xyp[1] < 0
		|| xyp[1] >= dimensions[1] || copy[xyp[1]][xyp[0]] == '1')
		return (0);
	else
	{
		if (copy[xyp[1]][xyp[0]] == 'E' || copy[xyp[1]][xyp[0]] == 'C')
		{
			map[xyp[1]][xyp[0]] = '0';
			return (1);
		}
		copy[xyp[1]][xyp[0]] = '1';
	}
	return (timber(map, copy, (int []){xyp[0] + 1, xyp[1]}, dimensions)
			|| timber(map, copy, (int []){xyp[0] - 1, xyp[1]}, dimensions)
			|| timber(map, copy, (int []){xyp[0], xyp[1] + 1}, dimensions)
			|| timber(map, copy, (int []){xyp[0], xyp[1] - 1}, dimensions));
}

int	parse_path(t_map map)
{
	int		n_coll;
	char	**cp1;
	char	**cp2;

	n_coll = 1;
	cp1 = copy2d(map.lines, map.height);
	if (!cp1)
		return (0);
	while (n_coll)
	{
		cp2 = copy2d(cp1, map.height);
		if (!cp2)
			break ;
		if (!timber(cp1, cp2, (int []){object_coords('P', map.lines,
					map.width, map.height)[0], object_coords('P', map.lines,
				map.width, map.height)[1]}, (int []){map.width, map.height}))
		{
			free_2d(cp2);
			break ;
		}
		n_coll = n_collect(cp1, map.width, map.height);
		free_2d(cp2);
	}
	free_2d(cp1);
	return (n_coll == 0);
}
