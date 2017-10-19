/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:01:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/19 19:13:46 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
*** - Draw lines using The Digital Differential Analyser -
*/

static inline void			set_pixel(float x, float y, t_img *img, t_color col)
{
	*((int *)(img->img_str) + (int)((int)x + (int)(y * 1920))) = col.color;
}

static inline t_dda_data	process_dda(t_line *line, t_map *map)
{
	t_dda_data data;

	data.start.x = ((line->origin->x * map->X_3D_X)
				+ (line->origin->y * map->Y_3D_X)
				+ (line->origin->z * map->Z_3D_X))
				* map->scaling
				+ map->offset.x;
	data.start.y = ((line->origin->x * map->X_3D_Y)
				+ (line->origin->y * map->Y_3D_Y)
				+ (line->origin->z * map->Z_3D_Y))
				* map->scaling
				+ map->offset.y;
	data.end.x = ((line->end->x * map->X_3D_X)
				+ (line->end->y * map->Y_3D_X)
				+ (line->end->z * map->Z_3D_X))
				* map->scaling
				+ map->offset.x;
	data.end.y = ((line->end->x * map->X_3D_Y)
				+ (line->end->y * map->Y_3D_Y)
				+ (line->end->z * map->Z_3D_Y))
				* map->scaling	
				+ map->offset.y;
	data.step = (fabsf(data.start.y - data.end.y)) > 
				(fabsf(data.start.x - data.end.x));
	return (data);
}

static inline void			swap(float *a, float *b, float *c, float *d)
{
	float					tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	tmp = *c;
	*c = *d;
	*d = tmp;
}

static inline void			dda(t_line *lines, t_color col, t_env env
							, t_map *map, t_img *img)
{
	float					tab[4];
	t_dda_data				data;
	float					delta;
	int						eps;

	data = process_dda(lines, map); 
	(data.step) ? swap(&data.start.x, &data.start.y, &data.end.x, &data.end.y)
			: 0 == 0;
	(data.start.x > data.end.x) ?
		swap(&data.end.x, &data.start.x, &data.end.y, &data.start.y)
		: 0 == 0;
	tab[0] = data.start.x;
	tab[1] = data.start.y;
	tab[2] = fabsf(data.start.x - data.end.x);
	tab[3] = fabsf(data.start.y - data.end.y);
	delta =  tab[2] / 2.0f;
	eps = (data.start.y < data.end.y) ? 1 : -1;
	while (tab[0] < data.end.x)
	{
		if (data.step)
			mlx_pixel_put(env.mlx, env.win, tab[1], tab[0], col.color);
		else
			mlx_pixel_put(env.mlx, env.win, tab[0], tab[1], col.color);
		tab[0]++;
		delta -= tab[3];
		if (delta < 0)
		{
			tab[1] += eps;
			delta += tab[2];
		}
	}
}

void						draw_line(t_map *map, t_color col, t_env env)
{
	t_line					*line;
	t_img					*img;

	line = map->lines;
	while (line)
	{
		dda(line, col, env, map, img);
		line = line->next;
	}
}
