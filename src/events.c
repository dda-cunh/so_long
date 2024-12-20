/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:33:58 by dda-cunh          #+#    #+#             */
/*   Updated: 2024/11/16 12:26:01 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_prog *program)
{
	if (keycode == 65307)
		return (killprogram(0, program));
	if (keycode == 119)
		try_move(E_PLAYER_UP, program);
	else if (keycode == 97)
		try_move(E_PLAYER_LEFT, program);
	else if (keycode == 115)
		try_move(E_PLAYER_DOWN, program);
	else if (keycode == 100)
		try_move(E_PLAYER_RIGHT, program);
	return (0);
}

int	killprogram(int keycode, t_prog *program)
{
	if (program)
	{
		if (program->map.lines)
			free_2d(program->map.lines);
		if (program->win_ptr)
			mlx_destroy_window(program->mlx_ptr, program->win_ptr);
		if (program->mlx_ptr)
		{
			mlx_loop_end(program->mlx_ptr);
			mlx_destroy_display(program->mlx_ptr);
			free(program->mlx_ptr);
		}
	}
	exit(exit_(keycode));
}

int	kill_x(void *program)
{
	exit(killprogram(0, program));
}
