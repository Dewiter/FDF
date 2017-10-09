/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:27:26 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/09 19:08:42 by rolevy           ###   ########.fr       */
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

// static inline int	extract_number(char *src, int index)
// {
// 	int				res;
// 	int				size_digit;
// 	char			*tmp;
	
// 	if (src[index] == '-')
// 		size_digit++;
// 	while (ft_isdigit(src[index]))
// 	{
// 		index++;
// 		size_digit++;
// 	}
// 	printf(RED"%s\n", src);
// 	// ft_strncpy(tmp, src + (index - size_digit), size_digit - index);
// 	res = ft_atoi(tmp);
// 	return (res);
// }

static inline t_map	*set_coords(char *file, t_map *map)
{
	int i;
	int index;
	int j;

	i = 0;
	j = 0;
	map->coords = (t_fpoint *)malloc(sizeof(t_fpoint) * (map->size + 1));
	map->coords[j].x = 50;
	map->coords[j].z = 50;
	while (file[i] != '\0')
	{
		index = 0;
		while(index < *map->width)
		{
			if ((!ft_isspace(file[i - 1]) || file[i - 1] == '-')
			&& (file[i] >= '0' && file[i] <= '9'))
			{
				map->coords[j].x = map->coords[j - 1].x + 50;
				// map->coords[j].y = extract_number(file, i);
				map->coords[j].z = map->coords[j - 1].z;
				printf(RED"value of X [%f]\n", map->coords[j].x);
				printf(BLUE"value of Z [%f]\n", map->coords[j].z);
				j++;
			}
			index++;
			i++;
		}
		map->coords[j - 1].z = map->coords[j - 2].z + 50;
		map->coords[j - 1].x = 50;
		printf("\n");
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