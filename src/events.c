/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:33:58 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/12 15:31:55 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	killprogram(int keycode, t_prog program)
{
	mlx_destroy_window(program.mlx_ptr, program.win_ptr);
	mlx_loop_end(program.mlx_ptr);
	do_free(program);
	return (keycode);
}
