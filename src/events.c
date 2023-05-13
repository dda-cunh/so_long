/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:33:58 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/13 22:27:12 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	killprogram(int keycode, t_prog *program)
{
	if (program)
	{
		mlx_destroy_window(program->mlx_ptr, program->win_ptr);
		mlx_loop_end(program->mlx_ptr);
		do_free(program);
	}
	return (keycode);
}
