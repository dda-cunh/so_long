/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:25:23 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/12 19:50:30 by dda-cunh         ###   ########.fr       */
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

void	do_free(t_prog program)
{
	free_2d(program.map.lines);
	free(program.mlx_ptr);
}
