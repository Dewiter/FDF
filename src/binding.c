/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:03:39 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/22 15:59:56 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*** - Binding keys to fucntions
*/

#include "../includes/fdf.h"

static inline int	quit(void)
{
	ft_putstr(RED"\nClosing fdf\n");
	exit(EXIT_SUCCESS);
	return (0);
}

static inline int	clear_win(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y <= env->height)
	{
		x = 0;
		mlx_pixel_put(env->mlx, env->win, x, y, set_color(BLACK).color);
		while (x <= env->width)
		{
			mlx_pixel_put(env->mlx, env->win, x, y, set_color(BLACK).color);
			x++;
		}
		y++;
	}
	return (0);
}

static inline int	check_key(int input, t_env *env)
{
	int				i;
	static t_key	tab[2] =
	{{51, &clear_win},
	{53, &quit}};

	i = 0;
	while (i <= 2)
	{
		if (tab[i].keycode == input)
			tab[i].function(env);
		i++;
	}
	return (0);
}

void				bind(t_env env)
{
	mlx_key_hook(env.win, check_key, &env);
}
