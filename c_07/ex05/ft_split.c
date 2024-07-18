/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:35:04 by mivogel           #+#    #+#             */
/*   Updated: 2024/07/11 15:42:22 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (check_charset(str[i], charset))
			i++;
		else
		{
			while (str[i] && !(check_charset(str[i], charset)))
				i++;
			cpt++;
		}
	}
	return (cpt);
}

int	len_word(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !(check_charset(str[i], charset)))
		i++;
	return (i);
}

char	*cpy_word(char *str, char *charset, int n)
{
	int		i;
	char	*c;

	i = 0;
	c = malloc(sizeof(char) * (len_word(str, charset) + 1));
	if (!(c))
		return (0);
	while (str[i] && i < n)
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**r;

	if (!str)
		return (0);
	r = malloc(sizeof(char *) * (count_word(str, charset) + 1));
	if (!r)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (check_charset(str[i], charset) == 1)
			i++;
		else
		{
			r[j] = cpy_word(&str[i], charset, len_word(&str[i], charset));
			j++;
			i = i + len_word(&str[i], charset);
		}
	}
	r[j] = 0;
	return (r);
}
/*
#include <stdio.h>
int	main(int ac, char *av[])
{
	if (ac != 3)
		return (0);
	char **tab = ft_split(av[1], av[2]);
	int i = -1;
	while (tab[++i])
		printf("%s\n", tab[i]);
}*/
