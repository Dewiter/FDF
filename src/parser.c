/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:27:26 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/09 15:18:55 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static inline char		*parse_map(char *raw, int fd, char **ref)
{
	char				*file;
	int					i;
	
	fd = open(ref[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &file))
	{
		if (i == 0)
		raw = ft_strdup(file);
		if (i >= 1)
		raw = ft_strjoin(raw, file);
		i++;
	}
	close(fd);
	return (raw);
}

static inline t_map	*set_coords(char *file, t_map *map)
{
	int i;
	int index;
	int j;

	i = 0;
	j = 1;
	while (file[i] != '\0')
	{
		index = 0;
		while(index <= *map->width)
		{
			if ((!ft_isspace(file[i - 1]) || file[i - 1] == '-')
			&& (file[i] >= '0' && file[i] <= '9'))
				map->coords[j].x += map->coords[j - 1].x + 10;
			map->coords[j].z += map->coords[j - 1].z;
			index++;
			i++;
		}
		map->coords[j].z += map->coords[j - 1].z + 10;
		(map->width)++;
		i++;
	}
	return (map);
}

static inline t_map	*init_map(t_map *map, int fd, char **ref)
{
	char			*file;

	map->raw = parse_map(map->raw, fd, ref);
	map->height = get_map_heigth(map->height, fd, ref);
	map->width = get_map_width(map->width, fd, ref);
	map->size = get_map_size(map->size, fd, map->raw);
	map->coords = (t_fpoint *)malloc(sizeof(t_fpoint) * map->size);
	map->coords[0].x = 0;
	map->coords[0].y = 0;
	map->coords[0].z = 0;
	return (map);
}

t_map					*parse(char **file)
{
	int		fd;
	t_map	*map;
	
	map = (t_map *)malloc(sizeof(t_map));
	map = init_map(map, fd, file);
	map = set_coords(map->raw, map);
	return (map);
}