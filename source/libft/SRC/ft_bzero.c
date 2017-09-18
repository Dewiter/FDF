/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:29:43 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/13 20:04:57 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = (unsigned char)NULL;
		i++;
	}
}
