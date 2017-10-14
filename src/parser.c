/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:27:26 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/14 17:42:23 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static inline t_fpoint	*create_point(float x, float y, char *line)
{
	t_fpoint			*point;

	point = (t_fpoint *)malloc(sizeof(t_fpoint));
	point->x = x;
	point->y = y;
	point->z = (float)ft_atoi(line);
	point->next = NULL;
	return (point);
}

static inline void		push_point(t_fpoint **ptr, t_fpoint *elem)
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

static inline void		set_coords(char **file,t_map *map)
{
	char 				*line;
	t_fpoint			*current;
	int 				fd;
	static float		tab[2] = {0, 0};
	static t_fpoint		*last = NULL;	

	fd  = open(file[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		current = NULL;
		tab[0] = 0;
		while (*line)
		{
			if (ft_isdigit(*line) || *line == '-')
			{
				push_point(&current, create_point(tab[0], tab[1], line));
				++tab[0];
			}	
			while (ft_isspace(*line))
				++line;
			++line;
		}
		tab[1]++;
		create_lines(map, current, last);
		last = current; 
	}
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
	set_coords(file, map);
	return (map);
}
