/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:36:32 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/15 14:52:47 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	keydown(int keycode, t_prog *program)
{
	if (keycode == 65307)
		return (killprogram(keycode, program));
	if (keycode == 119)
		try_move(1, program);
	else if (keycode == 97)
		try_move(2, program);
	else if (keycode == 115)
		try_move(3, program);
	else if (keycode == 100)
		try_move(4, program);
	return (0);
}
