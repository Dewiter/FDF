/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:01:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/18 16:13:09 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void    bresenham_right (int dx, int dy, t_index a, t_index b, void *mlx, void *win)
{
    int e;
    int x;
    int y;

    x = a.index_x;
    y = a.index_y;
    else if (dy == 0)
    {
        while (x++ <= b.index_x)
        {
            mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
            x++;
        }
    }
}

void    bresenham_left(int dx, int dy, t_index a, t_index b, void *mlx, void *win)
{
    int e;
    int x;
    int y;
    
    x  = a.index_x;
    y = a.index_y;
    if (dy > 0)
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
        if (dy < 0)
        {
            if (dx <= dy)
            {
                dx = (e = dx) * 2;
                dy *= 2;
                while (1)
                {
                    mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
                    if (x-- == b.index_x)
                        break;
                    if ((e -= dy) >= 0)
                    {
                        y--;
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
                    if (y-- == b.index_y)
                        break;
                    if ((e -= dx) >= 0)
                    {
                        x--;
                        e += dy;
                    }
                }
            }
        }
        if (dy == 0)
        {
            while (x >= b.index_x)
            {
                mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
                x--;
            }
        }
    }
}

void    bresenham_verticale(int dx, int dy, t_index a, t_index b, void *mlx, void *win)
{
    int x;
    int y;

    printf("1\n");
    x = a.index_x;
    y = a.index_y;
    if (dy > 0)
    {
        while (y <= b.index_y)
        {
            mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
            y++;
        }
    }
    if (dy < 0)
    {
        while (y >= b.index_y)
        {
            mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
            y--;
        }
    }
}

t_bresenham     bresenham_init(t_bresenham ref, t_index a, t_index b)
{
    ref.x = a.index_x;
    ref.y = a.index_y;
    ref.dx = b.index_x - a.index_x;
    ref.dy = b.index_y - a.index_y;
    return (ref);
}

void    Bresenham(t_index a, t_index b, t_env env)
{
    t_bresenham ref;

    ref = bresenham_init(ref, a, b);
    env.mlx = mlx_init();
    env.win = mlx_new_window(env.mlx, env.height, env.width. "FDF");
    if (ref.dx > 0)
        bresenham_right(ref, env)
    if (ref.dx < 0)
        bresenham_left(t_bresenham ref, t_env env);

}
int main(int ac, char **av)
{
    (void)ac;
    void *mlx;
    void *win;

    t_index a;
    t_index b;

    a.index_z = 0;
    b.index_z = 0;
    a.index_x = ft_atoi(av[1]);
    a.index_y = ft_atoi(av[2]);
    b.index_x = ft_atoi(av[3]);
    b.index_y = ft_atoi(av[4]);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 1000, "FDF");
    mlx_pixel_put(mlx, win, a.index_x, a.index_y, 0xFF0000);
    a.index_x++;
    a.index_y++;
    Bresenham(a, b, mlx, win);
    mlx_loop(mlx);
}