/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:08:44 by rolevy            #+#    #+#             */
/*   Updated: 2017/06/19 14:23:05 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main(int ac, char **av)
{

	int fd 	= open(av[1], O_RDONLY);
	int fd2 = open(av[2], O_RDONLY);
	int i;
	char *line;
	while (get_next_line((i % 2 == 0) ?  fd : fd2, &line) > 0)
	{
		printf("file number %d : %s\n", (i % 2 == 0) ? 1 : 2, line);
		i++;	
	}
}
