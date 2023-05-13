/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:36:32 by dda-cunh          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/13 22:06:58 by dda-cunh         ###   ########.fr       */
=======
/*   Updated: 2023/05/13 19:05:56 by dda-cunh         ###   ########.fr       */
>>>>>>> da2b6453d2a4f69ef5fcd5ad71f293ac2402a9fb
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	keydown(int keycode, t_prog *program)
{
	if (keycode == 65307)
	{
		killprogram(keycode, program);
		return (1);
	}
	ft_putnbr_fd(keycode, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
