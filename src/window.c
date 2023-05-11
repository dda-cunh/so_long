/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:12:04 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/11 18:09:32 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_prog	*new_program(int w, int h, char *title)
{
	void	*mlx_ptr;
	t_prog	*program;

	mlx_ptr = mlx_init();
	program = malloc(sizeof(t_prog));
	program->height = h;
	program->width = w;
	program->mlx_ptr = mlx_ptr;
	program->win_ptr = mlx_new_window(mlx_ptr, w, h, title);
	return (program);
}
