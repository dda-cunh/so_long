/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:25:23 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/11 21:00:50 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>

void	free_2d(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
			free(matrix[i++]);
		free(matrix);
	}
}

void	free_prog(t_prog *prog)
{
	if (prog)
	{
		if (prog->map)
		{
			if (prog->map->lines)
				free_2d(prog->map->lines);
			free(prog->map);
		}
		free(prog->mlx_ptr);
	}
}
