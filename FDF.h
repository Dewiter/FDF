/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:28:28 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/18 15:53:24 by rolevy           ###   ########.fr       */
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

typedef struct      s_bresenham
{
    int             x;
    int             y;
    int             e;
    int             dx;
    int             dy;   
}                   t_bresenham;

typedef struct      s_env
{
    void            *mlx;
    void            *win;
    int             height;
    int             width;
}

t_map       *get_map(char **source);

#endif