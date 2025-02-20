/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:41:11 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/20 14:11:39 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	**getmap(char *str, int fd)
// {
// }

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
