/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:28:28 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/30 15:04:32 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "source/minilibx/mlx.h"

# define RED        "\x1B[31m"
# define GREEN      "\x1B[32m"
# define YELLOW     "\x1B[33m"
# define BLUE       "\x1B[34m"

typedef struct      s_index
{
    int             index_x;
    int             index_y;
    int             index_z;    
}                   t_index;

typedef struct      s_map
{
    char            *raw;
    t_index         index;
    struct s_map    *next;
}                   t_map;
              

typedef struct      s_env
{
    int             height;
    int             width;
    void            *mlx;
    void            *win;
}                   t_env;

typedef  struct     s_bresenham
{
    int             e;
    int             x;
    int             y;
    int             max_x;
    int             max_y;
    int             max_axis;
    double          dx;
    double          dy;
    int             offset;
    double          delta;
    double          error;
}                   t_bresenham;

t_map               *get_map(char **source);
void                bresenham_right(t_bresenham ref, t_env);

#endif