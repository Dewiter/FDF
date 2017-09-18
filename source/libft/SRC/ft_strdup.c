/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:55:12 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/16 04:54:11 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*dest;

	dest = NULL;
	if ((dest = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))) == NULL)
		return (NULL);
	return (ft_strcpy(dest, src));
}
