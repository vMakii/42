/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:41:11 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/20 13:09:48 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_walls(char **tab, int len)
{
	int	i;
	int	j;
	int	max_i;

	i = -1;
	max_i = 0;
	while (tab[++i])
	{
		j = -1;
		if (max_i < i)
			max_i = i;
		while (tab[i][++j])
		{
			if (len < j)
				return (ft_printf("Error: not rectangle\n"), 0);
			if (tab[0][j] != '1' || tab[i][0] != '1' || tab[i][len] != '1')
				return (ft_printf("Error: no outer wall\n"), 0);
		}
	}
	j = -1;
	while (tab[max_i][++j])
		if (tab[max_i][j] != '1')
			return (ft_printf("Error: no outer wall\n"), 0);
	return (1);
}

int	ft_contains(char **tab)
{
	int	i;
	int	j;
	int	p;
	int	c;
	int	e;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
				p++;
			if (tab[i][j] == 'C')
				c++;
			if (tab[i][j] == 'E')
				e++;
		}
	}
	if (p != 1 || c < 1 || e != 1)
		return (ft_printf("Error: multiple or no key(s) element(s)\n"), 0);
	return (1);
}

void	ft_parsing(char **tab, int len)
{
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
