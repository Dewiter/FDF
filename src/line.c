/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:09:56 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/13 17:30:03 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void    push_line(t_line **ptr, t_line *elem)
{
    static t_line   *tmp = NULL;
    
    if (!(*ptr) || !tmp)
        *ptr = elem;
    else
        tmp->next = elem;
    tmp = elem;
}

t_line  *create_lines(t_fpoint *origin, t_fpoint *end)
{
    t_line  *line;

    line = (t_line *)malloc(sizeof(t_line));
    line->origin = origin;
    line->end = end;
    line->next = NULL;
    return (line);
}