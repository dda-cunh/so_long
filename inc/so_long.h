/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:18:19 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/11 20:17:28 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>


typedef struct s_map
{
	char	**lines;
	int		height;
	int		width;
}		t_map;

typedef struct s_prog
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	t_map	*map;
}		t_prog;

typedef struct s__img
{
	t_prog	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_image;

/* ************************************************************************** */
/*                                 window.c                                   */
/* ************************************************************************** */
t_prog			*new_program(int w, int h, char *title);

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
int				killprogram(int keycode, t_prog program);


/* ************************************************************************** */
/*                                  keys.c                                    */
/* ************************************************************************** */
int				keydown(int keycode, t_prog *window);

/* ************************************************************************** */
/*                                   map.c                                    */
/* ************************************************************************** */
t_map			*get_map(int mapfd, char *map_path);

#endif