/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:01:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/06 14:31:01 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static inline void			dda(t_color col, t_fpoint a, t_fpoint b, t_img *img)
{
	int						length;
	int						i;
	float					stepx;
	float					stepy;

	i = 0;
	if (fabs(b.x - a.x) >= fabs(b.y - a.y))
		length = fabs(b.x - a.x);
	else
		length = fabs(b.y - a.y);
	stepx = (b.x - a.x) / (float)length;
	stepy = (b.y - a.y) / (float)length;
	while (i <= length)
	{
		*(((int *)img->img_str) + (int)(a.y * img->y + a.x)) = col.color;
		a.x += stepx;
		a.y += stepy;
		i++;
	}
}

void						dda_init(t_fpoint a, t_fpoint b, t_env env,
							t_color col)
{
	t_img					img;

	img = create_img(img, env, env.height, env.width);
	dda(col, a, b, &img);
	mlx_put_image_to_window(env.mlx, env.win, img.img_ptr, 0, 0);
}
