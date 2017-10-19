/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:59:23 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/15 19:07:52 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
***  - Creating environement -
*/

t_env		create_env(t_env env)
{
	env.mlx = mlx_init();
	env.height = 1080;
	env.width = 1920;
	env.win = mlx_new_window(env.mlx, env.width, env.height, "FDF");
	return (env);
}
