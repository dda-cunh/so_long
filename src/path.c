/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:19:03 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/12 19:53:05 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	*playerxy(char **map, int width, int height)
{
	int	x;
	int	y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			if (map[y][x] == 'P')
				return ((int []){x, y});
	}
	return (NULL);
}

int	n_collect(char **map, int width, int height)
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

int	eat(char **map, int xyp[2], int dimensions[2], int collect)
{
	if (collect == 0)
		return (1);
	if (xyp[0] < 0 || xyp[0] >= dimensions[0]
		|| xyp[1] < 0 || xyp[1] >= dimensions[1])
		return (0);
	if (map[xyp[1]][xyp[0]] == '1')
		return (0);
	if (map[xyp[1]][xyp[0]] == 'C' || map[xyp[1]][xyp[0]] == 'E')
	{
		if (map[xyp[1]][xyp[0]] == 'C')
			map[xyp[1]][xyp[0]] = '-';
		else
			map[xyp[1]][xyp[0]] = '_';
		return (1);
	}
	return (eat(map, (int []){xyp[0] + 1, xyp[1]}, dimensions, collect)
			|| eat(map, (int []){xyp[0] - 1, xyp[1]}, dimensions, collect)
			|| eat(map, (int []){xyp[0], xyp[1] + 1}, dimensions, collect)
			|| eat(map, (int []){xyp[0], xyp[1] - 1}, dimensions, collect));
}
// WHY AM I GETTING STACK OVERFLOW??

int	parse_path(t_map map)
{
	int	good;

	good = 1;
	ft_putstr_fd("Reached parse_path\n", 1);
	while (good)
	{
		if (n_collect(map.lines, map.width, map.height) == 0)
			break ;
		ft_putstr_fd("Call to eat\n", 1);
		good = eat(map.lines, playerxy(map.lines, map.width, map.height),
				(int []){map.width, map.height},
				n_collect(map.lines, map.width, map.height));
	}
	return (good);
}
