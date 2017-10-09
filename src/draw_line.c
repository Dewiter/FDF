/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:01:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/09 15:21:33 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static inline void			dda(t_color col, t_fpoint a, t_fpoint b, t_img *img)
{
	int						length;
	int						i;
	float					stepx;
 	float					stepz;

	i = 0;
	if (fabs(b.x - a.x) >= fabs(b.y - a.y))
		length = fabs(b.x - a.x);
	else
		length = fabs(b.z - a.z);
	stepx = (b.x - a.x) / (float)length;
	stepz = (b.z - a.z) / (float)length;
	while (i <= length)
	{
		*(((int *)img->img_str) + (int)(a.z * img->y + a.x)) = col.color;
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
	while (i < map->size)
	{
		dda(col, map->coords[i], map->coords[i + 1], &img);
		(map->coords)++;
		i++;
	}
	mlx_put_image_to_window(env.mlx, env.win, img.img_ptr, 0, 0);
}
