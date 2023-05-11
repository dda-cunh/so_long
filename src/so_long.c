/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:02:32 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/11 20:59:23 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	parser(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		return (1);
	return (0);
}

int	so_long(int ac, char **av, t_prog *program)
{
	int		map_fd;

	if (parser(ac, av))
		return (1);
	map_fd = open(av[1], O_RDONLY, 0777);
	if (map_fd == -1)
		return (2);
	program->map = get_map(map_fd, av[1]);
	close(map_fd);
	if (!program->map)
		return (4);
	return (0);
}

int	main(int ac, char **av)
{
	t_prog	program;
	int		status;

	program = new_program(500, 500, "xdd");
	if (!program.mlx_ptr || !program.win_ptr)
		status = 3;
	else
		status = so_long(ac, av, &program);
	free_prog(&program);
	if (status)
	{
		ft_putstr_fd("Error\n", 2);
		if (status == 1)
			ft_putstr_fd("Bad arguments\n", 2);
		else if (status == 2)
		{
			ft_putendl_fd(strerror(errno), 2);
			status = errno;
		}
		else if (status == 3)
			ft_putstr_fd("Couldn't init program\n", 2);
		else if (status == 4)
			ft_putstr_fd("Bad map\n", 2);
	}
	return (status);
}
