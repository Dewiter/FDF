/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bressenham_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:31:25 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/18 16:11:39 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include        "../../../FDF.h"

static void     bresenham_delta_positive()
{
    if (ref.dx >= ref.dy)
    {
        ref.dx = (ref.e = ref.dx) * 2;
        ref.dy *= 2;
        while (ref.x++ <= b.index_x)
        {
            mlx_pixel_put(env.mlx, env.win ref.x, ref.y, 0xFFFFFF);
            if ((ref.e -= ref.dy) < 0)
            {
                ref.y++;
                ref.e += ref.dx;
            }
            ref.x++;
        }
    }
    else
    {
        ref.dy = (ref.e = ref.dy) * 2;
        ref.dx *= 2;
        while (ref.y++ <= b.index_x)
        {
            mlx_pixel_put(env.mlx, env.win ref.x, ref.y, 0xFFFFFF);
            if ((ref.e -= ref.dx) < 0)
            {
                ref.x++;
                ref.e += ref.dy;
            }
            ref.y++;
        }
    }
}

static void     bressenham_delta_negative(t_bresenham ref, t_env env, t_index a, t_index b)
{
    if (ref.dx >= -ref.dy)
    {
        ref.dx = (ref.e = ref.dx) * 2;
        ref.dy *= 2;
        while (1)
        {
            mlx_pixel_put(env.mlx, env.win, ref.x, ref.y, 0xFFFFFF);
            if (ref.x++ == b.index_x)
                break;
            if ((rev.e += ref.dy) < 0)
            {
                ref.y--;
                ref.e += ref.dx;
            }
        }
    }
    else
    {
        ref.dy = (ref.e = ref.dy) * 2;
        ref.dx *= 2;
        while (1)
        {
            mlx_pixel_put(env.mlx, env.win, ref.x, ref.y, 0xFFFFFF);
            if (ref.y-- == b.index_y)
                break;
            if ((ref.e += ref.dx) > 0)
            {
                ref.x++;
                ref.e += ref.dx;
            }
        }
    }
}

static void     bresenham_delta_null(t_bresenham ref, t_env env, t_index a, t_index b)
{
    while (ref.x++ <= b.index_x)
    {
        mlx_pixel_put(env.mlx, env.win, ref.x, ref.y, 0xFFFFFF);
        x++;
    }
}

void            bresenham_right(t_bresenham ref, t_env env, t_index a, t_index b)
{
    if (ref.dy > 0)
        bressenham_delta_positive(ref, env, a, b);
    if (ref.dy < 0)
        bressenham_delta_negative(ref, env, a, b);
    if (ref.dy = 0)
        bressenham_delta_null(ref, env, a, b);
}