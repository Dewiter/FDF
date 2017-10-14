/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:01:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/14 17:36:15 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static inline void	dda_hor(t_line *lines, t_color col, t_env env)
{
	float			x;
	float			y;

	x = lines->origin->x;
	y = lines->origin->y;
	while (x <= lines->end->x)
	{
		mlx_pixel_put(env.mlx, env.win, x, y, col.color);
		x++;
		y++;
	}
}

static inline void	dda_ver(t_line *lines, t_color col, t_env env)
{
	float			x;
	float			y;

	x = lines->origin->x;
	y = lines->origin->y;
	while (y <= lines->end->y)
	{
		mlx_pixel_put(env.mlx, env.win, x, y, col.color);
		y++;
	}
	mlx_pixel_put(env.mlx, env.win, lines->origin->x, lines->origin->y, 0xFFFFFF);
}

void				draw_line(t_map *map, t_color col, t_env env)
{
	while (map->lines->next)
	{
		dda_hor(map->lines, col, env);
		map->lines = map->lines->next;
	}
}
