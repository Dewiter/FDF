/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 20:33:36 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/14 20:47:04 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
*** - Creating points and lines -
*/

t_line		*create_line(t_fpoint *origin, t_fpoint *end)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	line->origin = origin;
	line->end = end;
	line->next = NULL;
	return (line);
}

void		create_lines(t_map *map, t_fpoint *current
			, t_fpoint *last)
{
	while (current || last)
	{
		if (current && current->next)
			push_line(&map->lines, create_line(current, current->next));
		if (current && last)
			push_line(&map->lines, create_line(current, last));
		current = (current) ? current->next : current;
		last = (last) ? last->next : last;
	}
}

t_fpoint	*create_point(float x, float y, char *line)
{
	t_fpoint*point;

	point = (t_fpoint *)malloc(sizeof(t_fpoint));
	point->x = x;
	point->y = y;
	point->z = (float)ft_atoi(line);
	point->next = NULL;
	return (point);
}
