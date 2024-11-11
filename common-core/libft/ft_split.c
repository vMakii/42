/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:08:24 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/11 10:45:13 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char const *s, char sep)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++i;
		while (*s && *s != sep)
			++s;
	}
	return (i);
}

void	ft_set(char **tab, char const *s, char sep)
{
	char		**tmp_tab;
	char const	*tmp_s;

	tmp_s = s;
	tmp_tab = tab;
	while (*tmp_s)
	{
		while (*s == sep)
			++s;
		tmp_s = s;
		while (*tmp_s && *tmp_s != sep)
			++tmp_s;
		if (*tmp_s == sep || tmp_s > s)
		{
			*tmp_tab = ft_substr(s, 0, tmp_s - s);
			s = tmp_s;
			++tmp_tab;
		}
	}
	*tmp_tab = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	ft_set(tab, s, c);
	return (tab);
}
