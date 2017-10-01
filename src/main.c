/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:54:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/01 17:07:22 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
    t_point a;
    t_point b;
	t_env env;

	(void)ac;

    a.x = ft_atoi(av[1]);
    a.y = ft_atoi(av[2]);
    b.x = ft_atoi(av[3]);
    b.y = ft_atoi(av[4]);

	env = create_env(env);
	bresenham(a, b, env);
	mlx_loop(env.mlx);
}