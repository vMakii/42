/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:21:39 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/23 14:14:31 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	split_and_trim(t_data *data)
{
	int		i;
	char	*trim;

	data->map.tab = ft_split(data->map.str, '\n');
	if (!data->map.tab)
		return (false);
	i = 0;
	while (data->map.tab[i] && i < 6)
	{
		trim = ft_strtrim(data->map.tab[i], " ");
		if (!trim)
			return (false);
		free(data->map.tab[i]);
		data->map.tab[i] = ft_strdup(trim);
		if (!data->map.tab[i])
			return (free(trim), false);
		free(trim);
		i++;
	}
	gc_add_tab(data->map.tab, &data->gc_list);
	return (true);
}

bool	read_file(char *filename, t_data *data)
{
	char	*line;
	int		fd;

	data->map.str = ft_strdup("");
	if (!data->map.str)
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (false);
	line = get_next_line(fd, 0);
	if (!line)
		return (close(fd), false);
	while (line)
	{
		data->map.str = ft_strjoin_free(data->map.str, line);
		free(line);
		if (!data->map.str)
			break ;
		line = get_next_line(fd, 0);
	}
	gc_add_malloc(data->map.str, &data->gc_list);
	if (close(fd) == -1 || split_and_trim(data) == false)
		return (false);
	return (true);
}
