/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:01:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/09 18:53:23 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static inline void			dda(t_color col, t_fpoint a, t_fpoint b, t_img *img,
							t_env env)
{
	float					length;
	int						i;
	float					stepx;
 	float					stepz;

	i = 0;
	if (b.x - a.x >= b.z - a.z)
		length = fabsf(b.x - a.x);
	else
		length = fabs(b.z - a.z);
	stepx = (b.x - a.x) / (float)length;
	stepz = (b.z - a.z) / (float)length;
	while (i <= length)
	{
		*(((int *)img->img_str) + (int)(a.x + (a.z * env.width))) = col.color;
		a.x += stepx;
		a.z += stepz;
		i++;
	}
}

void						dda_init(t_map *map, t_env env, t_color col)
{
	t_img					img;
	int						i;

	i = 0;
	img = create_img(img, env, env.height, env.width);
	while (i < 20)
	{
		dda(col, map->coords[i], map->coords[i + 1], &img, env);
		(map->coords)++;
		i++;
	}
	mlx_put_image_to_window(env.mlx, env.win, img.img_ptr, 0, 0);
}
