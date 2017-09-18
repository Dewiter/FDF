/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 22:53:21 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/12 01:31:38 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	if (src < dst)
	{
		while (len > 0)
		{
			a[len - 1] = b[len - 1];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (dst);
}
