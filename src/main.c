/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:54:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/14 21:00:50 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_env	env;
	t_color	color;
	t_map	*map;

	if (ac > 0)
	{
		env = create_env(env);
		color = set_color(0, 255, 0, 255);
		map = parse(av, env);
		draw_line(map, color, env);
		mlx_loop(env.mlx);
	}
}
