/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:01:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/14 20:43:07 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
*** - Draw lines using The Digital Differential Analyser -
*/

static inline void	dda(t_line *lines, t_color col, t_env env)
{
	float			stepx;
	float			stepy;
	int				length;
	int				i;

	if (fabs(lines->end->x - lines->origin->x) >=
		fabs(lines->end->y - lines->origin->y))
		length = fabs(lines->end->x - lines->origin->x);
	else
		length = fabs(lines->end->y - lines->origin->y);
	stepx = (lines->end->x - lines->origin->x) / length;
	stepy = (lines->end->y - lines->origin->y) / length;
	i = 0;
	while (i <= length)
	{
		mlx_pixel_put(env.mlx, env.win, lines->origin->x, lines->origin->y
						, col.color);
		lines->origin->x += stepx;
		lines->origin->y += stepy;
		i++;
	}
}

void				draw_line(t_map *map, t_color col, t_env env)
{
	while (map->lines->next)
	{
		dda(map->lines, col, env);
		map->lines = map->lines->next;
	}
}
