/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:49:04 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/04 12:04:48 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int     main()
{
    void *mlx;
    void *window;

    mlx     = mlx_init();
    window  = mlx_new_window(mlx, 1000, 1000, "test");
    mlx_pixel_put(mlx, window, 200, 200, 0x00FFFFFF);
    mlx_loop(mlx);
}