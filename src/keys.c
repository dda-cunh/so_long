/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:36:32 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/11 18:10:35 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	keydown(int keycode, t_prog *window)
{
	if (keycode == 65307)
	{
		killprogram(keycode, *window);
		return (1);
	}
	ft_putnbr_fd(keycode, 1);
	ft_putchar_fd('\n', 1);
	(void) window;
	return (0);
}