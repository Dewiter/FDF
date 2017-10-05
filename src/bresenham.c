/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:01:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/05 15:37:56 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static inline t_bres		assign_delta_error(t_bres ref, t_point a, t_point b)
{
	ref.offset = -1;
	ref.delta = (b.y - a.y) / (b.x - a.x);
	ref.eps = 0;
	return (ref);
}

static inline void			dir(t_img *img, t_point a,t_point b,
							t_bres ref, int color, t_env env)
{
	while (a.x <= b.x)
	{
		set_pixel(img, a, color);
		while ((ref.eps += ref.delta) >= 0)
		{
			a.y++;
			ref.eps += ref.offset;
		}
		a.x++;
	}
}

void						bresenham(t_point a, t_point b, t_env env)
{
	t_bres	ref;
	t_img	img;
	t_color	color;
	
	
	color.s.b = 255;
	color.s.g = 0;
	color.s.r = 0;
	ref = assign_delta_error(ref, a, b);
	// set_pixel(&img, a, color.s.r + color.s.g + color.s.b);
	img = create_img(img, env, env.height, env.width);
	dir(&img, a, b, ref, color.s.r + color.s.g + color.s.b, env);
	mlx_put_image_to_window(env.mlx, env.win, img.img_ptr, 0, 0);
	// mlx_put_image_to_window(env.mlx, env.win, img.img_ptr, 0, 0);
}