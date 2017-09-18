/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 00:06:14 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/13 22:20:41 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*tab;
	char const	*cpy;
	size_t		n;
	size_t		len;

	tab = dst;
	cpy = (char *)src;
	n = size;
	while (n-- != 0 && *tab)
		tab++;
	len = tab - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(cpy));
	while (*cpy)
	{
		if (n != 1)
		{
			*tab++ = *cpy;
			n--;
		}
		cpy++;
	}
	*tab = '\0';
	return (len + (cpy - src));
}
