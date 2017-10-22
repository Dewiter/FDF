/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:01:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/22 15:51:39 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
*** - Draw lines using The Digital Differential Analyser -
*/

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

static inline t_bres		set_values(t_bres bres, t_line *lines, t_env env
							, t_map *map)
{
	t_dda_data				data;

	data = process_dda(lines, map);
	bres.step = data.step;
	(data.step) ?
		swap(&data.start.x, &data.start.y, &data.end.x, &data.end.y) : 0 == 0;
	(data.start.x > data.end.x) ?
		swap(&data.end.x, &data.start.x, &data.end.y, &data.start.y) : 0 == 0;
	bres.tab[0] = data.start.x;
	bres.tab[1] = data.start.y;
	bres.tab[2] = data.end.x;
	bres.tab[3] = data.end.y;
	bres.tab[4] = fabsf(data.start.x - data.end.x);
	bres.tab[5] = fabsf(data.start.y - data.end.y);
	bres.delta = bres.tab[4] / 2.0f;
	bres.eps = (data.start.y < data.end.y) ? 1 : -1;
	return (bres);
}

static inline void			bresenham(t_line *lines, t_color col,
							t_env env, t_map *map)
{
	t_bres					bres;

	bres = set_values(bres, lines, env, map);
	while (bres.tab[0] < bres.tab[2])
	{
		if (bres.step)
			mlx_pixel_put(env.mlx, env.win, bres.tab[1],
							bres.tab[0], col.color);
		else
			mlx_pixel_put(env.mlx, env.win, bres.tab[0],
							bres.tab[1], col.color);
		bres.tab[0]++;
		bres.delta -= bres.tab[5];
		if (bres.delta < 0)
		{
			bres.tab[1] += bres.eps;
			bres.delta += bres.tab[4];
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
		bresenham(line, col, env, map);
		line = line->next;
	}
}
