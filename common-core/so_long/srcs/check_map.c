/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:41:11 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/20 14:22:39 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_mapcpy(char **tab)
{
	int		i;
	char	**cpy;

	i = 0;
	while (tab[i])
		i++;
	cpy = malloc(sizeof(char *) * (i + 1));
	if (!cpy)
		return (NULL);
	cpy[i] = NULL;
	while (--i >= 0)
	{
		cpy[i] = ft_strdup(tab[i]);
		if (!cpy[i])
			return (NULL);
	}
	return (cpy);
}

void	ft_parsing(char **tab, int len)
{
	// int	i;
	// int	j;
	//
	// i = 0;
	// j = 0;
	if (!ft_walls(tab, len) || !ft_contains(tab))
	{
		exit(0);
	}
}

int	ft_check_map(char *av)
{
	int		fd;
	int		len;
	char	*line;
	char	*str;
	char	**tab;

	str = ft_strdup("");
	if (!str)
		exit(0);
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(0);
	}
	line = get_next_line(fd);
	len = ft_strlen(line) - 2;
	while (line)
	{
		str = ft_strjoin(str, line);
		line = get_next_line(fd);
	}
	tab = ft_split(str, '\n');
	ft_parsing(tab, len);
	return (1);
}
