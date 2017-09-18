/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:09:58 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/14 19:21:00 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *save;

	save = (char *)NULL;
	while (*s)
	{
		if (*s == c)
			save = (char *)s;
		s++;
	}
	if (*s == c)
		save = (char *)s;
	return (save);
}
