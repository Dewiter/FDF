/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:27:26 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/07 17:27:48 by rolevy           ###   ########.fr       */
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

// static inline t_fpoint	*set_coords(t_map map, int fd, char **ref)
// {
// 		char 				*file;
// 		int					i;
// 		int					j;
// 		float				offset;
		
// 		fd = open(ref[1], O_RDONLY);
// 		offset = 50;
// 		i = 0;
		
// 		printf(MAG"Setting Coords\n");
// 		// while (get_next_line(fd, &file))
// 		// {
// 		// 	if 
// 		// }
// 		close(fd);
// 		return (map.coords);
// }
	
static inline t_map	*init_map(t_map *map, int fd, char **ref)
{
	char			*file;

	map->size = get_map_size(map->size, fd, ref);
	printf(BLUE"map->size = %d\n", map->size);
	map->raw = parse_map(map->raw, fd, ref);
	printf(BLUE"%s\n", map->raw);
	map->height = get_map_heigth(map->height, fd, ref);
	printf(BLUE"map->height = %d\n", map->height);
	map->width = get_map_width(map->width, fd, ref);
	for (int i = 0 ; i < map->height; i++)
		printf(BLUE"map->width = %i\n", map->width[i]);
	map->coords = (t_fpoint *)malloc(sizeof(t_fpoint) * map->size);
	map->coords[0].x = 0;
	map->coords[0].y = 0;
	map->coords[0].z = 0;
	printf(BLUE"Values [%f] [%f] [%f]\n", map->coords[0].x, map->coords[0].y, map->coords[0].z);
	return (map);
}

t_map					*parse(char **file)
{
	int		fd;
	t_map	*map;
	
	map = (t_map *)malloc(sizeof(t_map));
	map = init_map(map, fd, file);
	// map.coords = (t_fpoint *)malloc(sizeof(t_fpoint) * map.size);
	// printf(RED"%s\n", map->raw);
	// map.coords = set_coords(map.coords, fd, map.size, file, map.raw);
	return (map);
}