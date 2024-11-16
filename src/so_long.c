/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:02:32 by dda-cunh          #+#    #+#             */
/*   Updated: 2024/11/16 12:17:44 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_prog	new_program(int w, int h, char *title)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_prog){mlx_ptr, mlx_new_window(mlx_ptr, w, h, title),
		(t_map){(t_point_2d){0, 0}, NULL, 0, 0, 0, 0}});
}

static int	so_long(t_prog *program)
{
	mlx_hook(program->win_ptr, 2, 1L << 0, key_hook, program);
	mlx_hook(program->win_ptr, 17, 1L << 17, kill_x, program);
	mlx_loop(program->mlx_ptr);
	return (killprogram(0, program));
}

int	main(int ac, char **av)
{
	t_prog	program;
	t_map	map;
	int		map_fd;

	if (ac != 2)
		return (killprogram(1, NULL));
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		return (killprogram(6, NULL));
	map_fd = open(av[1], O_RDONLY, 0777);
	if (map_fd == -1)
		return (killprogram(2, NULL));
	map = get_map(map_fd, av[1]);
	close(map_fd);
	if (!map.lines || map.width < 3 || map.height < 3)
		return (killprogram(4, NULL));
	if (!parse_path(&map))
	{
		free_2d(map.lines);
		return (killprogram(5, NULL));
	}
	program = new_program(SQUARE_SIZE * map.width, SQUARE_SIZE * (map.height + 1),
							"so_long");
	if (!program.mlx_ptr || !program.win_ptr)
		return (killprogram(3, &program));
	program.map = map;
	render_map(&program);
	return (so_long(&program));
}
