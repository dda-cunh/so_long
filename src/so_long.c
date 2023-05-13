/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:02:32 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/13 22:29:25 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	so_long(t_prog *program)
{
	mlx_key_hook(program->win_ptr, keydown, program);
	mlx_hook(program->win_ptr, 17, 1L << 17, killprogram, program);
	mlx_loop(program->mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_prog	program;
	t_map	map;
	int		map_fd;
	int		status;

	program = (t_prog){NULL, NULL, 0, 0, (t_map){NULL, 0 ,0}};
	if (ac != 2)
		return (exit_(1, NULL));
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		return (exit_(6, NULL));
	map_fd = open(av[1], O_RDONLY, 0777);
	if (map_fd == -1)
		return (exit_(2, NULL));
	map = get_map(map_fd, av[1]);
	close(map_fd);
	if (!map.lines || map.width < 3 || map.height < 3)
		return (exit_(4, NULL));
	program = new_program(8 * 8 * map.width, 8 * 8 * map.height, "so_long");
	if (!program.mlx_ptr || !program.win_ptr)
		return (exit_(3, &program));
	program.map = map;
	if (!parse_path(program.map))
		return (exit_(5, &program));
	status = so_long(&program);
	return (exit_(status, &program));
}
