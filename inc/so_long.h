/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:18:19 by dda-cunh          #+#    #+#             */
/*   Updated: 2024/11/16 12:30:41 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>

# define SQUARE_SIZE 32

#define CELL_COLLECTABLE	'C'
#define CELL_EXIT_OPEN		'X'
#define CELL_PLAYER			'P'
#define CELL_FLOOR			'0'
#define CELL_WALL			'1'
#define CELL_EXIT			'E'


typedef enum e_event
{
	E_NONE,
	E_PLAYER_UP,
	E_PLAYER_LEFT,
	E_PLAYER_DOWN,
	E_PLAYER_RIGHT
}		t_event;

typedef struct s_point_2d
{
	int	x;
	int	y;
}		t_point_2d;

typedef struct s_map
{
	t_point_2d	player_coords;
	char		**lines;
	int			width;
	int			height;
	int			pmoves;
	char		underp;
	int			n_coll;
}		t_map;

typedef struct s_prog
{
	void	*mlx_ptr;
	void	*win_ptr;
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
void		put_object(char object, t_prog *p, int event, t_point_2d coords);
void		render_map(t_prog *p);
char		*get_path(char object, int event);

/* ************************************************************************** */
/*                                  image.c                                   */
/* ************************************************************************** */
t_image		new_image(int w, int h, t_prog window);
void		print_blend(t_prog *prog, t_image t, t_image u, t_point_2d coords);
void		footer(t_prog *program);
int			get_pixel_color(t_image image, int x, int y);


/* ************************************************************************** */
/*                                events.c                                    */
/* ************************************************************************** */
int			killprogram(int keycode, t_prog *program);
int			key_hook(int keycode, t_prog *window);
int			kill_x(void *program);

/* ************************************************************************** */
/*                                  map.c                                     */
/* ************************************************************************** */
t_map		get_map(int mapfd, char *map_path);

/* ************************************************************************** */
/*                                 utils.c                                    */
/* ************************************************************************** */
int			exit_(int status);
char		**copy2d(char **map, int height);
char		**copy2d(char **map, int height);
void		putstr_footer(t_prog *program, int y, int color);
void		clearendbl(char **matrix);
void		free_2d(char **matrix);

/* ************************************************************************** */
/*                                  path.c                                    */
/* ************************************************************************** */
int			parse_path(t_map *map);

/* ************************************************************************** */
/*                                player.c                                    */
/* ************************************************************************** */
t_point_2d	object_coords(char object, t_map *map);
void		try_move(t_event direction, t_prog *program);
void		move_player(t_prog *prog, int event, int *coords);

#endif