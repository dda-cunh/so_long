/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:25:25 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/11 20:16:53 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	get_height(int mapfd)
{
	int		r;
	int		n_lines;
	char	*line;

	r = 1;
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

static int	get_width(int mapfd)
{
	char	*line;
	int		width;

	line = get_next_line(mapfd);
	close(mapfd);
	if (!line)
		return (-1);
	width = ft_strlen(line);
	free(line);
	return (width);
}

static int	parse_map(char **lines)
{
	return (0);
}

static char	**get_lines(int mapfd)
{
	char	**lines;

	return (lines);
}

t_map	*get_map(int mapfd, char *map_path)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		close(mapfd);
		return (NULL);
	}
	map->width = get_width(mapfd);
	if (map->width == -1)
		return (NULL);
	mapfd = open(map_path, O_RDONLY, 0777);
	map->height = get_height(mapfd);
	if (map->height == -1)
		return (NULL);
	mapfd = open(map_path, O_RDONLY, 0777);
	map->lines = get_lines(mapfd);
	close(mapfd);
	if (!map->lines)
		return (NULL);
	if (parse_map(map->lines))
		return (NULL);
	return (map);
}
