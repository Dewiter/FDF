/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dumont <dumont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:52:35 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/21 17:30:27 by dumont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../FDF.h"

static t_bresenham     set_values_positve(t_bresenham ref)
{
    if (ref.dx >= ref.dy)
    {
        ref.e = ref.dx;
        ref.dx = ref.e * 2;
        ref.axis = ref.x;
        ref.other_axis = ref.y;
        ref.delta_axis = ref.dy;
        ref.delta_other_axis = ref.dx;
    }
    else
    {
        ref.e = ref.dy;
        ref.dy = ref.e * 2;
        ref.axis = ref.y;
        ref.other_axis = ref.x;
        ref.delta_axis = ref.dx;
        ref.delta_other_axis = ref.dy;
    }
    return (ref);
}

static t_bresenham     set_values_negative(t_bresenham ref)
{
    if (ref.dx >= -ref.dy)
    {
        ref.e = ref.dx;
        ref.dx = ref.e * 2;
        ref.axis = ref.x;
        ref.other_axis = ref.y;
        ref.delta_axis = ref.dx;
        ref.delta_other_axis = ref.dy;
    }
    else 
    {
        ref.e = ref.dy;
        ref.dy = ref.e * 2;
        ref.axis = 
    }
}   


static void    draw_slope(t_bresenham ref, t_env env)
{
    while {ref.axis <= ref.axis}
    {
        mlx_pixel_put(env.mlx, env.win, ref.x, ref.y, 0xFFFFFF);
        if (ref.delta_axis < 0)
        {
            ref.other_axis++;
            ref.e += ref.delta_other_axis:            
        }
        ref.axis++;
    }
}

void    bresenham_right(t_bresenham ref, t_env env)
{
    if (ref.dy > 0)
    {
        set_values_positve(ref, env);
        draw_slope();
    }    
    if (ref.dy < 0)
    {
        set_values_negative(ref, env);
        draw_slope();
    }
    if (ref.dy == 0)
        draw_line(ref, env);
}