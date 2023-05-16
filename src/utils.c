/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:25:23 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/16 18:27:01 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	clearendbl(char **matrix)
{
	int	x;
	int	y;

	if (matrix)
	{
		y = -1;
		while (matrix[++y])
		{
			x = -1;
			while (matrix[y][++x])
			{
				if (!matrix[y][x + 1] && matrix[y][x] == '\n')
				{
					matrix[y][x] = '\0';
					break ;
				}
			}
		}
	}
}

void	free_2d(char **matrix)
{
	int	i;

	if (matrix)
	{
		i = -1;
		while (matrix[++i])
			free(matrix[i]);
		free(matrix);
	}
}

char	**copy2d(char **map, int height)
{
	int		i;
	char	**cp;

	cp = malloc(sizeof(char *) * (height + 1));
	if (!cp)
		return (0);
	cp[height] = NULL;
	i = -1;
	while (++i < height)
		cp[i] = ft_strdup(map[i]);
	return (cp);
}

int	exit_(int status)
{
	if (status)
		ft_putstr_fd("Error\n", 2);
	if (status == 1)
		ft_putstr_fd("\tBad arguments\n", 2);
	else if (status == 2)
	{
		ft_putendl_fd(strerror(errno), 2);
		status = errno;
	}
	else if (status == 3)
		ft_putstr_fd("\tCouldn't init program\n", 2);
	else if (status == 4)
		ft_putstr_fd("\tBad map\n", 2);
	else if (status == 5)
		ft_putstr_fd("\tThere's no valid path\n", 2);
	else if (status == 6)
		ft_putstr_fd("\tFile isn't .ber format\n", 2);
	return (status);
}

void	putstr_footer(t_prog *program, int y, int color)
{
	char	*moves;

	moves = ft_itoa(program->map.pmoves);
	mlx_string_put(program->mlx_ptr, program->win_ptr,
		program->map.width * 32 / 2 - 32, y + 22, color, "MOVES :");
	mlx_string_put(program->mlx_ptr, program->win_ptr,
		program->map.width * 32 / 2 + 22, y + 22, color, moves);
	free (moves);
}
