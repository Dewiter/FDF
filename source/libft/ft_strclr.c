/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:07:04 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/27 15:26:16 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	ft_strclr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		*s = '\0';
		s++;
	}
}
