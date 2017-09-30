/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:01:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/30 15:23:54 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"


static void            draw(t_bresenham ref, t_env env)
{
    while (ref.x < ref.max_x)
    {
        mlx_pixel_put(env.mlx, env.win, ref.x, ref.y, 0xFFFFFF);
        if ((ref.error)++ >= 0.5)
        {
            printf(BLUE);
            printf("Values of [y] : %d\n", ref.y);
            (ref.y)++;
            ref.error += ref.offset;
        }
        printf(BLUE);
        printf("Values of [x] : %d\n", ref.x);
        (ref.x)++;
    }
}


t_bresenham     bresenham_init(t_bresenham ref, t_index a, t_index b)
{
    ref.x = a.index_x;
    ref.y = a.index_y;
    ref.max_x = b.index_x;
    ref.max_y = b.index_y;
    printf(GREEN);
    ref.delta = (ref.dy) / (ref.dx);
    printf("[OK] ref.delta\n");
    ref.offset = -1.0;
    printf("[OK] ref.offset\n");
    ref.error = 0.0;
    printf("[OK] ref.error\n");
    ref.error = ref.delta;  
    ref.dx = b.index_x - a.index_x;
    ref.dy = b.index_y - a.index_y;
    return (ref);
}

void    Bresenham(t_index a, t_index b, t_env env)
{
    t_bresenham ref;

    printf(YELLOW);
    printf("[Setting environement ...] \n");
    printf(GREEN);
    printf("[OK] Environement\n");
    printf(YELLOW);
    printf("[Setting values for current points ...]\n");
    ref = bresenham_init(ref, a, b);
    printf(GREEN);
    printf("[OK] Values\n");
    printf(YELLOW);
    printf("[Drawing ...]\n");
    draw(ref, env);
    printf(GREEN);
    printf("Finished !\n");

}
int main(int ac, char **av)
{
    (void)ac;

    t_index a;
    t_index b;
    t_env env;

    a.index_z = 0;
    b.index_z = 0;
    a.index_x = atoi(av[1]);
    a.index_y = atoi(av[2]);
    b.index_x = atoi(av[3]);
    b.index_y = atoi(av[4]);
    env.mlx = mlx_init();
    env.win = mlx_new_window(env.mlx, 800, 800, "FDF");
    a.index_x++;
    a.index_y++;
    Bresenham(a, b, env);
    mlx_loop(env.mlx);
}