/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:19:42 by mbeilles          #+#    #+#             */
/*   Updated: 2017/05/02 16:23:15 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void		*ft_memalloc_char(size_t size, char c)
{
	char	*tab;
	size_t	t;

	if ((tab = (char*)malloc(size)) == NULL)
		return (NULL);
	t = 0;
	while (t < size)
	{
		tab[t] = c;
		t++;
	}
	return (tab);
}
