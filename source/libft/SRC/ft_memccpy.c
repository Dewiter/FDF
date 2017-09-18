/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 22:15:05 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/12 01:26:14 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	while (i < n)
	{
		a[i] = b[i];
		if ((unsigned char)c == b[i])
			return (a + i + 1);
		i++;
	}
	return (NULL);
}
