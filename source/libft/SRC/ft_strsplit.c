/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:21:35 by mbeilles          #+#    #+#             */
/*   Updated: 2017/04/20 00:26:37 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

static void	*dealloc_tab(char **tab, size_t index)
{
	while (index + 1 > 0)
	{
		free(tab[index - 1]);
		index--;
	}
	free(tab);
	return (NULL);
}

static int	get_words(char *str, char c)
{
	int		i;
	int		word;
	int		in_word;

	i = 0;
	word = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (!in_word)
			{
				in_word = 1;
				word++;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (word);
}

static char	*cut_word(char *str, char c)
{
	int		i;
	int		j;
	char	*str_return;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	j = i;
	i = 0;
	if ((str_return = (char*)malloc(sizeof(char) * j + 1)) == NULL)
		return (NULL);
	while (i < j)
	{
		str_return[i] = str[i];
		i++;
	}
	str_return[i] = '\0';
	return (str_return);
}

static char	*get_word(char *str, int w, char c)
{
	int		i;
	int		word;
	int		in_word;

	i = 0;
	word = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (!in_word)
			{
				in_word = 1;
				word++;
				if (word == w)
					return (cut_word(&str[i], c));
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (&str[i]);
}

char		**ft_strsplit(char const *str, char c)
{
	int		i;
	int		k;
	char	*str_return_of_the_jedi;
	char	**tab;

	i = 0;
	if ((tab = (char**)malloc(sizeof(tab) * (get_words((char *)str, c) + 1)))
			== NULL)
		return (NULL);
	while (i < get_words((char *)str, c))
	{
		k = 0;
		str_return_of_the_jedi = get_word((char *)str, i + 1, c);
		while (str_return_of_the_jedi[k])
			k++;
		if ((tab[i] = (char*)malloc(sizeof(tab[i]) * k + 1)) == NULL)
			return (dealloc_tab(tab, i));
		tab[i] = &*str_return_of_the_jedi;
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
