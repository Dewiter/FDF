/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:28:28 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/30 17:32:22 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "../source/minilibx/mlx.h"

/*
*** Color syntax macros
*/

# define RED        "\x1B[31m"
# define GREEN      "\x1B[32m"
# define YELLOW     "\x1B[33m"
# define BLUE       "\x1B[34m"



typedef struct      s_point
{
    int             x;
    int             y;
    int             z;    
}                   t_point;

/*
*** Map stats
*/

typedef struct      s_map
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

/*
*** Bresenham Strcuture
*/

typedef  struct     s_bresenham
{
    int             x;
    int             y;
    int             max_x;
    int             max_y;
    int             offset;
    int             dir_x;
    int             dir_y;
    double          dx;
    double          dy;
    double          delta;
    double          error;
}                   t_bresenham;

t_map               *get_map(char **source);
void                bresenham_right(t_bresenham ref, t_env);

#endif