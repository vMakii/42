/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:41:11 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/25 14:48:53 by mivogel          ###   ########.fr       */
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

void	ft_printmap(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}

void	ft_parsing(t_map map)
{
	int		len;
	char	**cpy;

	len = ft_strlen(map.tab[0]) - 1;
	cpy = ft_mapcpy(map.tab);
	ft_printmap(cpy);
	if (!ft_walls(map.tab, len) || !ft_contains(map.tab)
		|| !ft_validexit(map.tab))
		ft_exit_map(map);
}

char	**ft_readmap(int fd)
{
	int		len;
	char	*str;
	char	*line;
	char	**tab;

	str = ft_strdup("");
	if (!str)
		return (NULL);
	line = get_next_line(fd);
	len = ft_strlen(line) - 2;
	while (line)
	{
		str = ft_strjoin_free(str, line);
		free(line);
		line = get_next_line(fd);
	}
	// ft_check_str(str);
	tab = ft_split(str, '\n');
	free(str);
	return (tab);
}

t_map	ft_check_map(char *av)
{
	int		fd;
	t_map	map;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(0);
	}
	map = ft_map(fd);
	ft_parsing(map);
	return (map);
}
