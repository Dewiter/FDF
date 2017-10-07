/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:59:23 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/06 14:16:10 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_env		create_env(t_env env)
{
	env.mlx = mlx_init();
	env.height = 800;
	env.width = 800;
	env.win = mlx_new_window(env.mlx, env.height, env.width, "FDF");
	return (env);
}
