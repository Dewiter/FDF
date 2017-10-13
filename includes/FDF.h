/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:28:28 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/13 17:47:36 by rolevy           ###   ########.fr       */
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

# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAG		"\x1B[35m"

/*
*** ----------------- Environement --------------------
*/

typedef	struct		s_env
{
	int				height;
	int				width;
	void			*mlx;
	void			*win;
}					t_env;

/*
*** ----------------- Coords --------------------------
*/

typedef	struct		s_fpoint
{
	float			x;
	float			y;
	float			z;
	struct s_fpoint	*next;
}					t_fpoint;

typedef struct		s_line
{
	t_fpoint		*origin;
	t_fpoint		*end;
	struct s_line	*next;
}					t_line;

/*
*** ----------------- Map -----------------------------
*/

typedef	struct		s_map
{
	int				size;
	int				*width;
	int				height;
	char			*raw;
	t_line			*line;
}					t_map;

/*
*** ------------------ Image --------------------------
*/

typedef	struct		s_img
{
	void			*img_ptr;
	char			*img_str;
	int				bpp;
	int				endian;
	int				l;
	int				y;
	int				x;
}					t_img;

/*
*** ----------------- Color ---------------------------
*/

typedef	struct		s_sub_color
{
	int				r;
	int				g;
	int				b;
	int				alpha;
}					t_sub_color;

typedef	union		u_color
{
	int				color;
	t_sub_color		s;
}					t_color;

/*
*** ----------------- Functions -----------------------
*/

/*
*** - Parsing 
*/
t_map				*get_map(char **source);
t_map				*parse(char **file);
t_map				*init_map(t_map *map, int fd, char **ref);
t_line				*create_lines(t_fpoint *origin, t_fpoint *end);
void				push_line(t_line **ptr, t_line *elem);

/*
*** - Environement
*/

t_env				create_env(t_env env);

/*
*** - Draw
*/

void				draw_line(t_map *map, t_color col, t_env env);

t_img				create_img(t_img img, t_env env, int x, int y);
t_color				set_color(int r, int g, int b);

#endif
