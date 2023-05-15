/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:18:19 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/15 16:51:53 by dda-cunh         ###   ########.fr       */
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
	void	*img_ptr;
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
int				render_map(t_prog *program, int event);
t_prog			new_program(int w, int h, char *title);

/* ************************************************************************** */
/*                                 colors.c                                   */
/* ************************************************************************** */
int				create_argb(int t, int r, int g, int b);

/* ************************************************************************** */
/*                                  image.c                                   */
/* ************************************************************************** */
t_image			new_image(int w, int h, t_prog window);

/* ************************************************************************** */
/*                                events.c                                    */
/* ************************************************************************** */
int				killprogram(int keycode, t_prog *program);


/* ************************************************************************** */
/*                                  keys.c                                    */
/* ************************************************************************** */
int				keydown(int keycode, t_prog *window);

/* ************************************************************************** */
/*                                  map.c                                     */
/* ************************************************************************** */
t_map			get_map(int mapfd, char *map_path);

/* ************************************************************************** */
/*                                 utils.c                                    */
/* ************************************************************************** */
int				exit_(int status, t_prog program);
char			**copy2d(char **map, int height);
char			**copy2d(char **map, int height);
void			free_2d(char **matrix);
void			clearendbl(char **matrix);

/* ************************************************************************** */
/*                                  path.c                                    */
/* ************************************************************************** */
int				parse_path(t_map map);

/* ************************************************************************** */
/*                                player.c                                    */
/* ************************************************************************** */
void			try_move(int direction, t_prog *program);
int				*object_coords(char object, char **map, int width, int height);

#endif