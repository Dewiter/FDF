/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bressenham_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:09:31 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/18 16:15:27 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include        "../../../FDF.h"

static void     bressenham_delta_positive(t_bresenham ref, t_env env, t_index a, t_index b)
{
    if (-dx >= dy)
    {
        dx = (e = dx) * 2;
        dy *= 2;
        while (1)
        {
            mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
            if (x-- == b.index_x)
                break;
            if ((e += dy) >= 0)
            {
                y++;
                e += dx;
            }
        }
    }
    else
    {
        dy = (e = dy) * 2;
        dx *= 2;
        while (1)
        {
            mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
            if (y++ == b.index_y)
                break;
            if ((e += dx) <= 0)
            {
                x--;
                e += dy;
            }
        }
    }
}

static void     bressenham_delta_negative(t_bresenham ref, t_env env, t_index a, t_index b)
{

}

static void     bressenham_delta_null(t_bresenham ref, t_env env, t_index a, t_index b)
{

}

void    bressenham_left(t_bresenham ref, t_env env)
{
    if (ref.dy > 0)
        bressenham_delta_positive(ref, env, a, b);
    if (ref.dy < 0)
        bressenham_delta_negative(ref, env, a, b);
    if (ref.dy = 0)
        bressenham_delta_null(ref, env, a, b);
}