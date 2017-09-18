/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slope.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:36:49 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/17 12:01:47 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FDF.h"
#include "source/libft/libft.h"

float    slope(t_index a, t_index b)
{
    int slope;
    int y_slope;
    int x_slope;

    y_slope = b.index_y - a.index_y;
    x_slope = b.index_x - a.index_x;
    slope = y_slope / x_slope;
    return (slope);
}
