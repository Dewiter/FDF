/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_stat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:39:21 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/13 16:52:38 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static inline int	get_map_size(int size, char *file)
{
	int				i;
	int				check;

	size = 0;
	i = 0;
	if (file[0] >= '0' && file[i] <= '9')
		size++;
	while (file[i] != '\0')
	{
		if ((!ft_isspace(file[i - 1]) || file[i - 1] == '-'
		|| file[i - 1] == '\n') && (file[i] >= '0' && file[i] <= '9'))
			size++;
		i++;
	}
	return (size);
}

static inline int	get_map_heigth(int height, char *raw)
{
	height = 0;
	while (*raw)
	{
		if (*raw == '\n')
			height++;
		raw++;
	}
	return (height);
}

static inline int	*get_map_width(int *width, int height, char *raw)
{
	int				length;
	int				i;

	i = 0;
	width = (int *)malloc(sizeof(int) * height);
	while (*raw)
	{
		length = 0;
		while (*raw != '\n')
		{
			length++;
			raw++;
		}
		if (length != 0)
		{
			width[i] = length;
			i++;
		}
		raw++;
	}
	return (width);
}

static inline char	*parse_map(char *raw, int fd, char **ref)
{
	char			*file;
	int				i;
	int				end;

	fd = open(ref[1], O_RDONLY);
	i = 0;
	end = 0;
	while (get_next_line(fd, &file))
	{
		if (i == 0)
			raw = ft_strdup(file);
		if (i > 0)
			raw = ft_strjoin(raw, file);
		end += ft_strlen(file);
		raw[end] = '\n';
		i++;
	}
	close(fd);
	return (raw);
}

t_map				*init_map(t_map *map, int fd, char **ref)
{
	char			*file;

	map->raw = parse_map(map->raw, fd, ref);
	map->size = get_map_size(map->size, map->raw);
	map->height = get_map_heigth(map->height, map->raw);
	map->width = get_map_width(map->width, map->height, map->raw);
	return (map);
}
