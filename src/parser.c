/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:27:26 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/14 20:41:49 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
*** - Parsing of Map into list of lines -
*/

static inline void		set_coords(char **file, t_map *map, t_env env)
{
	int					fd;
	char				*line;
	static t_fpoint		*last = NULL;
	t_fpoint			*current;
	static float		tab[2] = {0, 0};

	fd = open(file[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tab[0] = 0;
		current = NULL;
		while (*line)
		{
			if (ft_isdigit(*line) || *line == '-')
				push_point(&current, create_point(tab[0] += 50, tab[1], line));
			while (ft_isspace(*line))
				line++;
			line++;
		}
		tab[1] += 50;
		create_lines(map, current, last);
		last = current;
	}
}

t_map					*parse(char **file, t_env env)
{
	t_map				*map;
	t_line				*list_line;
	t_line				*line_holder;

	map = (t_map *)malloc(sizeof(t_map));
	set_coords(file, map, env);
	return (map);
}
