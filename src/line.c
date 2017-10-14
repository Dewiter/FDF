/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:09:56 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/14 17:44:01 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				push_line(t_line **ptr, t_line *elem)
{
	static t_line	*tmp = NULL;

	if (!(*ptr) || !tmp)
		*ptr = elem;
	else
		tmp->next = elem;
	tmp = elem;
}

t_line				*create_line(t_fpoint *origin, t_fpoint *end)
{
	t_line			*line;

	line = (t_line *)malloc(sizeof(t_line));
	line->origin = origin;
	line->end = end;
	line->next = NULL;
	return (line);
}

void				create_lines(t_map *map, t_fpoint *current, t_fpoint *last)
{
	while (current || last)
	{
		if (current && current->next)
		{
			push_line(&map->lines, create_line(current, current->next));
			printf(MAG"Conecting point A [%.0f, %.0f] B [%.0f, %.0f]\n", current->x, current->y, current->next->x, current->next->y);
		}
		if (current && last)
		{
			push_line(&map->lines, create_line(current, last));
			printf(BLUE"Conecting point A [%.0f, %.0f] B [%.0f, %.0f]\n", current->x, current->y, last->x, last->y);
		}
		current = (current) ?  current->next : current;
		last = (last) ? last->next : last;	
	}
}