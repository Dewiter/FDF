/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:28:28 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/05 16:13:11 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../source/minilibx/mlx.h"
# include "../source/libft/libft.h"
# include <stdio.h>

/*
*** Color macros
*/

# define GREEN      "\x1B[32m"
# define YELLOW     "\x1B[33m"
# define BLUE       "\x1B[34m"
# define MAG        "\x1B[35m"

typedef struct  s_point
{
    int         x;
    int         y;
    int         z;
}               t_point;

/*
*** Map stats
*/

typedef struct  s_map
{
    char            *raw;
    t_point         index;
    struct s_map    *next;
}                   t_map;

/*
***  Environement strutcure
*/

typedef struct      s_env
{
    int             height;
    int             width;
    void            *mlx;
    void            *win;
}                   t_env;

typedef struct  s_img
{
    void        *img_ptr;
    char        *img_str;
    int        bpp;
    int        y;
    int        x;
    int        l;
    int         endian;
}               t_img;

/*
*** Bresenham Strcuture
*/
typedef struct s_sub_color
{
    int			r;
    int			g;
    int			b;
    int			alpha;
}               t_sub_color;

typedef union	u_color
{
	int         color;
    t_sub_color s;
}               t_color;


typedef  struct     s_bresenham
{
    int             offset;
    double          delta;
    int         	eps;
}                   t_bres;

t_map               *get_map(char **source);
t_env               create_env(t_env env);
void                bresenham(t_point, t_point b, t_env);
t_img           	create_img(t_img img, t_env env, int x, int y);
void                set_pixel(t_img *img, t_point point, int color);

#endif
