/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-cunh <dda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:18:19 by dda-cunh          #+#    #+#             */
/*   Updated: 2023/05/09 22:49:34 by dda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s__img
{
	t_win	win;
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
t_win			new_program(int w, int h, char *title);

/* ************************************************************************** */
/*                                  image.c                                   */
/* ************************************************************************** */
t_image			new_image(int w, int h, t_win window);

#endif