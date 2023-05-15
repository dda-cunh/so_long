/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:25:25 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/15 15:22:54 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	get_height(int mapfd)
{
	int		n_lines;
	char	*line;

	n_lines = 0;
	line = "foo";
	while (line)
	{
		line = get_next_line(mapfd);
		if (line)
		{
			if (line[0] == '\0')
			{	
				free(line);
				close(mapfd);
				return (-1);
			}
			free(line);
			n_lines++;
		}
	}
	close(mapfd);
	return (n_lines);
}

static int	parse_help(t_map map, int var[3], int x, int y)
{
	char	c;

	y = -1;
	while (++y < map.height)
	{
		if ((int)ft_strlen(map.lines[y]) != map.width)
			return (1);
		x = -1;
		while (++x < map.width)
		{
			c = map.lines[y][x];
			if ((c != 'P' && c != 'E' && c != 'C' && c != '0' && c != '1')
				|| (x == 0 && c != '1') || (x == map.width - 1 && c != '1'))
				return (1);
			if (c == 'P')
				var[0]++;
			else if (c == 'E')
				var[2]++;
			else if (c == 'C')
				var[1]++;
		}
	}
	if (!var[1] || var[0] != 1 || var[2] != 1)
		return (1);
	return (0);
}

static int	parse_map(t_map map)
{
	int	i;

	if (map.lines && *map.lines)
	{
		i = -1;
		while (map.lines[0][++i])
			if (map.lines[0][i] != '1')
				return (1);
		if (parse_help(map, (int []){0, 0, 0}, -1, -1))
			return (1);
		i = -1;
		while (map.lines[map.height - 1][++i])
			if (map.lines[map.height - 1][i] != '1')
				return (1);
	}
	return (0);
}

static char	**get_lines(int mapfd, t_map map)
{
	char	**lines;
	int		i;

	lines = malloc(sizeof(char *) * (map.height + 1));
	if (!lines)
		return (NULL);
	i = -1;
	while (++i < map.height)
		lines[i] = get_next_line(mapfd);
	lines[map.height] = NULL;
	return (lines);
}

t_map	get_map(int mapfd, char *map_path)
{
	t_map	map;

	map.lines = NULL;
	map.height = get_height(mapfd);
	if (map.height == -1)
		return (map);
	mapfd = open(map_path, O_RDONLY, 0777);
	map.lines = get_lines(mapfd, map);
	close(mapfd);
	if (!map.lines || !*(map.lines) || !**(map.lines))
	{
		free_2d(map.lines);
		map.lines = NULL;
		return (map);
	}
	clearendbl(map.lines);
	map.width = ft_strlen(*(map.lines));
	if (parse_map(map))
	{
		free_2d(map.lines);
		map.lines = NULL;
	}
	map.pmoves = 0;
	return (map);
}
