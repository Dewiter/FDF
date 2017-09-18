/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:21:45 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/14 19:09:48 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./source/GNL/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "./source/libft/libft.h"
#include "./FDF.h"

void    set_position(t_map *map)
{
    int i;
    int index_x;
    int index_z;
    
    index_x = 0;
    index_z = 0;
    while(map->next)
    {
        i = 0;
        while(map[i].raw)
        {
            map->index.index_x = index_x;
            map->index.index_z = index_z;
            if (*map[i].raw != '0')
                map->index.index_y = ft_atoi(map[i].raw);
            map->index.index_y = 0;
            index_x++;
            index_z++;
            i++;
            printf("%d\n", map->index.index_x);
        }
        index_z += 1;
        map->next = map;
    }
}

t_map       *get_map(char **source)
{
    t_map   *map;
    char    *raw;
    int     fd;
    fd = open(source[1], O_RDONLY);
    // printf("1");
    if ((map = (t_map*)malloc(sizeof(t_map))) == NULL)
        return (NULL);
    // printf("%s\n", map->raw);
    while(get_next_line(fd, &raw) > 0 && map->next)
    {
        map->raw = (char *)malloc(sizeof(char) * ft_strlen(raw));
        ft_strcat(map->raw, raw);
        printf("%s\n", map->raw);
        // set_position(map);
        map = map->next;
    }
    return (map);
}


int     main(int ac, char **av)
{
    t_map *test;
    (void)ac;
    // test = (t_map*)malloc(sizeof(t_map));
    test = get_map(av);
    // while (test->next)
    // {
    //     printf("%d\n", test->index.index_x);
    //     test = test->next;
    // }
}