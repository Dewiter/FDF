/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:27:26 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/13 17:43:52 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static inline t_fpoint	*create_point(t_fpoint input)
{
	t_fpoint			*point;

	point = (t_fpoint *)malloc(sizeof(t_fpoint));
	point->x = input.x;
	point->y = input.y;
	point->z = input.z;
	point->next = NULL;
	return (point);
}

static inline void		push(t_fpoint **ptr, t_fpoint *elem)
{
	t_fpoint			*tmp;

	if (!(*ptr))
		*ptr = elem;
	else
	{
		tmp = *ptr;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

static inline t_fpoint	*set_coords(char *file, t_map *map)
{
	t_fpoint			*list_point;
	t_fpoint			*holder;
	t_fpoint			point;

	point.y = 0;
	while (*file)
	{
		if ((!ft_isspace(*(file - 1)) || *(file - 1) == '-'
		|| *(file - 1) == '\n') && (*file >= '0' && *file <= '9'))
		{
			holder = create_point(point);
			push(&list_point, holder);
			file++;
			point.x += 50;
		}
		if (*file == '\n')
		{
			point.x = 0;
			point.y += 50;
			file++;
		}
		file++;
	}
	return (list_point);
}

t_map					*parse(char **file)
{
	int					fd;
	t_map				*map;
	t_fpoint			*coords;
	t_line				*list_line;
	t_line				*line_holder;

	map = (t_map *)malloc(sizeof(t_map));
	map = init_map(map, fd, file);
	coords = set_coords(map->raw, map);
	while (coords->next)
	{
		line_holder = create_lines(coords, coords->next);
		push_line(&list_line, line_holder);
		coords = coords->next;
	}
	map->line = list_line;
	return (map);
}
