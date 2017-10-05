/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:42:36 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/05 13:51:13 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void set_pixel(t_img *img, t_point point, int color)
{
	*(((int*)img->img_str) + (point.y * img->y + point.x)) = color;
}

t_img	create_img(t_img img, t_env env, int x, int y)
{
	img.img_ptr = mlx_new_image(env.mlx, x, y);
	img.img_str = mlx_get_data_addr(img.img_ptr, &(img.bpp), &(img.l),
					&(img.endian));
	img.x = x;
	img.y = y;
	return (img);
}
