/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:54:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/23 16:42:38 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static inline t_map		*init_matrix(t_map *map)
{
	t_fpoint	cam;

	map->scaling = 50;
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

void					check_file(char **av)
{
	if (open(av[1], O_RDONLY) < 0)
	{
		ft_putstr(RED"FILE DOSN'T EXISTS\n");
		exit(EXIT_FAILURE);
	}
	if (!ft_strstr(av[1], ".fdf"))
	{
		ft_putstr(RED"FILE MUST BE OF TYPE .fdf\n");
		exit(EXIT_FAILURE);
	}
}

int						main(int ac, char **av)
{
	t_color				color;
	t_map				*map;
	t_env				env;

	if (ac >= 1)
	{
		check_file(av);
		env = create_env(env);
		if (ac == 6)
			color = set_color(ft_atoi(av[2]), ft_atoi(av[3]),
					ft_atoi(av[4]), ft_atoi(av[5]));
		else
		{
			ft_putstr("\nNot enough color info given setting color to white\n");
			color = set_color(WHITE);
		}
		map = parse(av, env);
		init_matrix(map);
		draw_line(map, color, env);
		bind(env);
		mlx_loop(env.mlx);
	}
	else
		ft_putstr(RED"please enter a map \n");
}
