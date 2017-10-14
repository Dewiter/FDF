/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:59:23 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/14 20:44:16 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
***  - Creating environement -
*/

t_env		create_env(t_env env)
{
	env.mlx = mlx_init();
	env.height = 1920;
	env.width = 1080;
	env.win = mlx_new_window(env.mlx, env.height, env.width, "FDF");
	return (env);
}
