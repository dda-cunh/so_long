/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:19:03 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/16 19:06:03 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	eat(char **map, char **copy, int xyp[2], int dimensions[2]);

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

static int	try(char **map, char **copy, int xyp[2], int dimensions[2])
{
	char	**cp;
	int		path;

	cp = copy2d(copy, dimensions[1]);
	path = eat(map, cp, (int []){xyp[0], xyp[1]}, dimensions);
	free_2d(cp);
	return (path);
}

static int	eat(char **map, char **copy, int xyp[2], int dimensions[2])
{
	int		collect;

	collect = n_collect(copy, dimensions[0], dimensions[1]);
	if (!collect)
		return (1);
	if (xyp[0] < 0 || xyp[0] >= dimensions[0] || xyp[1] < 0
		|| xyp[1] >= dimensions[1] || copy[xyp[1]][xyp[0]] == '1')
		return (0);
	if (copy[xyp[1]][xyp[0]] == '0')
		copy[xyp[1]][xyp[0]] = '1';
	if (copy[xyp[1]][xyp[0]] == 'C' || copy[xyp[1]][xyp[0]] == 'E')
	{
		copy[xyp[1]][xyp[0]] = '1';
		map[xyp[1]][xyp[0]] = '0';
		return (1);
	}
	return (try(map, copy, (int []){xyp[0] + 1, xyp[1]}, dimensions)
			|| try(map, copy, (int []){xyp[0] - 1, xyp[1]}, dimensions)
			|| try(map, copy, (int []){xyp[0], xyp[1] + 1}, dimensions)
			|| try(map, copy, (int []){xyp[0], xyp[1] - 1}, dimensions));
}

int	parse_path(t_map map)
{
	int		good;
	int		n_coll;
	char	**cp1;
	char	**cp2;

	good = 1;
	n_coll = n_collect(map.lines, map.width, map.height);
	cp1 = copy2d(map.lines, map.height);
	while (good && n_coll)
	{
		cp2 = copy2d(cp1, map.height);
		good = eat(cp1, cp2, (int []){object_coords('P', map.lines, map.width,
					map.height)[0], object_coords('P', map.lines, map.width,
					map.height)[1]}, (int []){map.width, map.height});
		if (good)
			n_coll--;
		free_2d(cp2);
	}
	free_2d(cp1);
	return (good);
}
