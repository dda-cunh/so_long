/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:02:32 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/16 22:17:05 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_prog	new_program(int w, int h, char *title)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_prog){mlx_ptr, mlx_new_window(mlx_ptr, w, h, title),
		w, h, (t_map){NULL, 0, 0, 0, 0}, (t_map){NULL, 0, 0, 0, 0}});
}

static int	so_long(t_prog *program)
{
	program->mapold = (t_map){copy2d(program->map.lines, program->map.height),
		program->map.width, program->map.height, 0, '0'};
	print_floor(program);
	render_map(program, 0, 1);
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

	program = (t_prog){NULL, NULL, 0, 0, (t_map){NULL, 0, 0, 0, 0},
		(t_map){NULL, 0, 0, 0, 0}};
	if (ac != 2)
		return (killprogram(1, &program));
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		return (killprogram(6, &program));
	map_fd = open(av[1], O_RDONLY, 0777);
	if (map_fd == -1)
		return (killprogram(2, &program));
	map = get_map(map_fd, av[1]);
	close(map_fd);
	if (!map.lines || map.width < 3 || map.height < 3)
		return (killprogram(4, &program));
	program = new_program(32 * map.width, 32 * (map.height + 1), "so_long");
	if (!program.mlx_ptr || !program.win_ptr)
		return (killprogram(3, &program));
	program.map = map;
	if (!parse_path(program.map))
		return (killprogram(5, &program));
	return (so_long(&program));
}
