/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:36:32 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/14 15:09:14 by dda-cunh         ###   ########.fr       */
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
