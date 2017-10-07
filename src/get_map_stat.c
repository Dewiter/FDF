/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_stat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:39:21 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/07 17:10:28 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_map_size(int size, int fd, char **ref)
{
	char	*file;
	int		i;
	
	fd = open(ref[1], O_RDONLY);
	size = 0;
	while (get_next_line(fd, &file))
	{
		i = 0;
		if (file[0] >= '0' && file[0] <= '9')
			size++;
		while (i <= ft_strlen(file))
		{
			if ((!ft_isspace(file[i - 1]) || file[i - 1] == '-')
			&& (file[i] >= '0' && file[i] <= '9'))
				size++;
			i++;
		}
	}
	close(fd);
	return (size);
}

int			get_map_heigth(int height, int fd, char **ref)
{
	char	*file;

	fd = open(ref[1], O_RDONLY);
	height = 0;
	while (get_next_line(fd, &file) > 0)
		height++;
	close(fd);
	return (height);
}

int			*get_map_width(int *width, int fd, char **ref)
{
	char *file;
	int height;
	int	i;
	
	i = 0;
	fd = open(ref[1], O_RDONLY);
	height = get_map_heigth(height, fd, ref);
	width = (int *)malloc(sizeof(int) * (height));
	while (get_next_line(fd, &file) && i <= height)
	{
		width[i] = ft_strlen(file);
		i++;
	}
	close(fd);
	return (width);
}
