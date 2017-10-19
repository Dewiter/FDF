/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:54:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/19 17:51:21 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static inline t_map		*init_matrix(t_map *map)
{
	t_fpoint	cam;
	
	map->scaling = 50;
	// cam = (t_fpoint){-M_PI / 4, -M_PI / 4, 3 * M_PI / 4};
	cam = (t_fpoint){-0.65, -0.8, -0.1};
	map->X_3D_X = (cos(cam.x) * cos(cam.z)
				- sin(cam.x) * cos(cam.y) * sin(cam.z));
	map->X_3D_Y = (-cos(cam.x) * sin(cam.z)
				- sin(cam.x) * cos(cam.y) * cos(cam.z));
	map->Z_3D_X = (sin(cam.x) * cos(cam.z)
				+ cos(cam.x) * cos(cam.y) * sin(cam.z));
	map->Z_3D_Y = (-sin(cam.x) * sin(cam.z)
				+ cos(cam.x) * cos(cam.y) * cos(cam.z));
	map->Y_3D_X = (sin(cam.y) * sin(cam.z));
	map->Y_3D_Y = (sin(cam.y) * cos(cam.z));
	map->offset = (t_vec2){1920 / 2, 1080 / 2};
	return (map);
}

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
		init_matrix(map);
		draw_line(map, color, env);
		mlx_loop(env.mlx);
	}
}
