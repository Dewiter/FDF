/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dumont <dumont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:28:28 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/20 12:39:26 by dumont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "source/minilibx/mlx.h"

typedef struct      s_index
{
    int         index_x;
    int         index_y;
    int         index_z;    
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
    void            *env;
}

typedef  struct     s_bresenham
{
    int             e;
    int             x;
    int             y;
    int             max_x;
    int             max_y;
    int             dx;
    int             dy;
    int             axis;
    int             other_axis;
    int             delta_axis;
    int             delta_other_axis;
}

t_map       *get_map(char **source);

#endif