/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:42:48 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/14 13:41:06 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*map;
	unsigned int	i;
	unsigned int	j;

	if ((map = ft_strdup(s)) == NULL)
		return (NULL);
	j = ft_strlen(map);
	i = 0;
	while (i < j)
	{
		map[i] = f(map[i]);
		i++;
	}
	return (map);
}
