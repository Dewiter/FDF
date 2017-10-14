/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:42:36 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/14 16:21:49 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_img		create_img(t_img img, t_env env, int x, int y)
{
	img.img_ptr = mlx_new_image(env.mlx, x, y);
	img.img_str = mlx_get_data_addr(img.img_ptr, &(img.bpp), &(img.l),
					&(img.endian));
	img.x = x;
	img.y = y;
	return (img);
}

t_color		set_color(int b, int g, int r, int a)
{
	t_color color;

	color.color = (b << 24) + (g << 16) + (r << 8) + (a);
	return (color);
}
