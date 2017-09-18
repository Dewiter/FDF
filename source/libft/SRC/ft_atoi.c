/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 05:36:13 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/16 01:26:50 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char const *str)
{
	long			i;
	unsigned long	nbr;
	int				negative;

	i = 0;
	nbr = 0;
	negative = 1;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((unsigned char)str[i] && (unsigned char)str[i] >= '0' &&
		(unsigned char)str[i] <= '9')
	{
		nbr *= 10;
		nbr += (long)((unsigned char)str[i] - '0');
		i++;
	}
	return ((int)(nbr * negative));
}
