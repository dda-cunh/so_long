/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:18:19 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/16 19:14:17 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**lines;
	int		width;
	int		height;
	int		pmoves;
	char	underp;
}		t_map;

typedef struct s_prog
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	t_map	map;
}		t_prog;

typedef struct s__img
{
	t_prog	win;
	void	*ptr;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		endian;
	int		line_len;
}		t_image;

/* ************************************************************************** */
/*                                 window.c                                   */
/* ************************************************************************** */
void			put_object(char object, t_prog *p, int event, int *coords);
void			render_map(t_prog *program, int event);
t_prog			new_program(int w, int h, char *title);

/* ************************************************************************** */
/*                                  image.c                                   */
/* ************************************************************************** */
int				get_pixel_color(t_image image, int x, int y);
void			print_blend(t_prog *prog, t_image t, t_image u, int *coords);
t_image			new_image(int w, int h, t_prog window);
void			print_floor(t_prog *program);

/* ************************************************************************** */
/*                                events.c                                    */
/* ************************************************************************** */
int				killprogram(int keycode, t_prog *program);
int				key_hook(int keycode, t_prog *window);
int				kill_x(void *program);

/* ************************************************************************** */
/*                                  map.c                                     */
/* ************************************************************************** */
t_map			get_map(int mapfd, char *map_path);

/* ************************************************************************** */
/*                                 utils.c                                    */
/* ************************************************************************** */
int				exit_(int status);
char			**copy2d(char **map, int height);
char			**copy2d(char **map, int height);
void			putstr_footer(t_prog *program, int y, int color);
void			clearendbl(char **matrix);
void			free_2d(char **matrix);

/* ************************************************************************** */
/*                                  path.c                                    */
/* ************************************************************************** */
int				parse_path(t_map map);

/* ************************************************************************** */
/*                                player.c                                    */
/* ************************************************************************** */
int				*object_coords(char object, char **map, int width, int height);
void			try_move(int direction, t_prog *program);

#endif