/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:28:28 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/07 17:02:23 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../source/minilibx/mlx.h"
# include "../source/libft/libft.h"
# include "../source/GNL/get_next_line.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

/*
*** ----------------- Color macros --------------------
*/

# define RED	"\x1B[31m"
# define GREEN	"\x1B[32m"
# define YELLOW	"\x1B[33m"
# define BLUE	"\x1B[34m"
# define MAG	"\x1B[35m"

/*
*** ----------------- Environement --------------------
*/

typedef	struct	s_env
{
	int			height;
	int			width;
	void		*mlx;
	void		*win;
}				t_env;

/*
*** ----------------- Coords --------------------------
*/

typedef	struct	s_fpoint
{
	float		x;
	float		y;
	float		z;
}				t_fpoint;

/*
*** ----------------- Map -----------------------------
*/

typedef	struct	s_map
{
	int			size;
	int			*width;
	int			height;
	char		*raw;
	t_fpoint	*coords;
	 
}				t_map;

/*
*** ------------------ Image --------------------------
*/

typedef	struct	s_img
{
	void		*img_ptr;
	char		*img_str;
	int			bpp;
	int			endian;
	int			l;
	int			y;
	int			x;
}				t_img;

/*
*** ----------------- Color ---------------------------
*/

typedef	struct	s_sub_color
{
	int			r;
	int			g;
	int			b;
	int			alpha;
}				t_sub_color;

typedef	union	u_color
{
	int			color;
	t_sub_color	s;
}				t_color;

/*
*** ----------------- Functions -----------------------
*/

t_map			*get_map(char **source);
t_env			create_env(t_env env);
t_img			create_img(t_img img, t_env env, int x, int y);
void			dda_init(t_fpoint a, t_fpoint b, t_env env, t_color col);
t_color			set_color(int r, int g, int b);
t_map			*parse(char **file);
int				get_map_heigth(int height, int fd, char **ref);
int				*get_map_width(int *width, int fd, char **ref);
int				get_map_size(int size, int fd, char **ref);

#endif
