/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:51:08 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/16 12:40:16 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	ft_check_extension(const char *filename)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(filename);
	if (len <= 4 || filename[len - 4] != '.' || filename[len - 3] != 'c'
		|| filename[len - 2] != 'u' || filename[len - 1] != 'b')
	{
		ft_printerr("Invalid file extension: Expected .cub\n");
		return (false);
	}
	return (true);
}

static bool	ft_check(t_data *data, char *map_file)
{
	int	fd;

	(void)data; // To avoid unused parameter warning
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		return (ft_printerr("Opening map file"), false);
	}
	return (true);
}

// This function would handle the parsing of the map file.
// For now, we will just print the file name.
bool	ft_parsing(t_data *data, char *map_file)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	printf("Parsing map file: %s\n", map_file);
	if (!ft_check_extension(map_file) || !ft_check(data, map_file))
		return (false);
	data->map = map;
	return (true);
}
