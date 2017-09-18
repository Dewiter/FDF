/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 14:10:54 by rolevy            #+#    #+#             */
/*   Updated: 2017/09/16 17:53:43 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *atox(char *hexa)
{
    int pos;
    int i;
    char *col;

    pos = 0;
    i = 2;
    // while (*hexa != 'F' || *hexa != '0')
    //     hexa++;
    printf("%s\n",hexa);
    while (hexa[i] != '\0' && pos <= 6)
    {
        if (hexa[i] == 'F' && hexa[i + 1] == 'F' && i == 2)
            col = RED;
        if (hexa[i] == 'F' && hexa[i + 1] == 'F' && i == 4)
            col = GREEN;
        if (hexa[i] == 'F' && hexa[i + 1] == 'F' && i == 6)
            col = BLUE;
        i++;
    }
    return (col);
}

int     main(int ac, char **av)
{
    printf("%s", atox(av[1]));
}