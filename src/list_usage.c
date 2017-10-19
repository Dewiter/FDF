/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 20:30:02 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/15 15:07:01 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
***  - Usage for lists of points and lines -
*/

void				push_point(t_fpoint **ptr, t_fpoint *elem)
{
	t_fpoint*tmp;

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

void				push_line(t_line **ptr, t_line *elem)
{
	static t_line	*tmp = NULL;

	if (!(*ptr) || !tmp)
		*ptr = elem;
	else
		tmp->next = elem;
	tmp = elem;
}
