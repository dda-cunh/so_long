/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:02:32 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/09 23:02:43 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_win	program;
	t_image	image;

	(void) ac;
	(void) av;
	program = new_program(500, 500, "xdd");
	if (!program.mlx_ptr || !program.win_ptr)
		return (1);
	image = new_image(300, 300, program);
	ft_memcpy(image.addr, "s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf", 500*500);
	mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
	mlx_destroy_image(program.mlx_ptr, image.img_ptr);
	mlx_loop(program.mlx_ptr);
	return (0);
}
