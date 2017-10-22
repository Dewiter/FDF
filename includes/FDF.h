/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:28:28 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/22 16:01:38 by rolevy           ###   ########.fr       */
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
# include <stdint.h>

/*
*** ----------------- Color macros --------------------
*/

# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAG		"\x1B[35m"

/*
*** ----------------- FDF Colors Macros ---------------
*/

# define WHITE		255, 255, 255, 255
# define BLACK		0, 0, 0, 0

/*
*** ---------------- Matrix macros --------------------
*/

# define X_3D_X		matrix[0][0]
# define X_3D_Y		matrix[0][1]
# define Y_3D_X		matrix[1][0]
# define Y_3D_Y		matrix[1][1]
# define Z_3D_X		matrix[2][0]
# define Z_3D_Y		matrix[2][1]

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
*** ----------------- Coords --------------------------
*/

typedef struct		s_vec2
{
	float			x;
	float			y;
}					t_vec2;

typedef	struct		s_fpoint
{
	float			x;
	float			y;
	float			z;
	t_color			col;
	struct s_fpoint	*next;
}					t_fpoint;

typedef struct		s_line
{
	t_fpoint		*origin;
	t_fpoint		*end;
	struct s_line	*next;
}					t_line;

typedef struct		s_dda_data
{
	t_vec2			start;
	t_vec2			end;
	int32_t			length;
	int				step;
}					t_dda_data;

typedef struct		s_bres
{
	float			tab[6];
	float			delta;
	int				eps;
	int				step;
}					t_bres;

/*
*** ----------------- Map -----------------------------
*/

typedef	struct		s_map
{
	t_line			*lines;
	t_fpoint		*points;
	int				width;
	int				height;
	t_vec2			offset;
	float			matrix[3][2];
	char			*raw;
	float			scaling;
	t_env			*env;
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
*** ----------------- Keys ----------------------------
*/

typedef struct		s_key
{
	int				keycode;
	int				(*function)();
}					t_key;

/*
*** ----------------- Functions -----------------------
*/

/*
*** - Parsing
*/

t_map				*parse(char **file, t_env env);
void				push_point(t_fpoint **ptr, t_fpoint *elem);
void				push_line(t_line **ptr, t_line *elem);
t_line				*create_line(t_fpoint *origin, t_fpoint *end);
void				create_lines(t_map *map, t_fpoint *current
					, t_fpoint *last);
t_fpoint			*create_point(int x, int y, char *line);

/*
*** - Environement
*/

t_env				create_env(t_env env);

/*
*** - Draw
*/

void				draw_line(t_map *map, t_color col, t_env env);
void				update_offset(float x, float y, t_map *map);
void				clear_screan();

/*
*** - Binding
*/

void				bind(t_env env);

t_img				*create_img(t_img *img, t_env env, int x, int y);
t_color				set_color(int b, int g, int r, int a);

#endif
