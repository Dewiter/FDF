/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:01:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/01 17:06:23 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


static void            draw(t_bresenham ref, t_env env)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    if (ref.dir_x < 0)
    {
        printf(YELLOW);
        printf("[DIR of x is neg]\n");
        i = -ref.dx;
    }
    if (ref.dir_y < 0)
    {
        printf(YELLOW);
        printf("[DIR of y is neg]\n");
        j = -ref.dy;
    }
    while (i < ref.dx)
    {
        mlx_pixel_put(env.mlx, env.win, ref.x, ref.y, 0xFFFFFF);
        if (ref.error++ >= 0 && j < ref.dy) 
        {
            j++;
            ref.y++;
            ref.error += ref.offset;
        }
        i++;
        ref.x++;
    }
}


static t_bresenham      set_dir(t_bresenham ref)
{
    if (ref.x < ref.max_x && ref.y < ref.max_y)
    {
        ref.dir_x = 1;
        ref.dir_y = 1;
    }
    if (ref.x < ref.max_x)
        ref.dir_x = -1;
    if (ref.y < ref.max_y)
        ref.dir_y = -1;
    return (ref);
}

static t_bresenham      bresenham_init(t_bresenham ref, t_point a, t_point b)
{
    ref.x = a.x;
    ref.y = a.y;
    ref.max_x = b.x;
    ref.max_y = b.y;
    printf(GREEN);
    ref.delta = (ref.dy) / (ref.dx);
    printf("[OK] ref.delta\n");
    ref.offset = -1.0;
    printf("[OK] ref.offset\n");
    ref.error = 0.0;
    printf("[OK] ref.error\n");
    ref.error = ref.delta;  
    ref.dx = b.x - a.x;
    ref.dy = b.y - a.y;
    return (ref);
}

void                    bresenham(t_point a, t_point b, t_env env)
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
    printf("[Setting DIR]\n");
    ref = set_dir(ref);
    printf(GREEN);
    printf("[OK] DIR\n");
    printf(YELLOW);
    printf("[Drawing ...]\n");
    draw(ref, env);
    printf(GREEN);
    printf("Finished !\n");

}