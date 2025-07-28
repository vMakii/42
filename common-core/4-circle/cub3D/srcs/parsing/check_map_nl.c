/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_nl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:18:25 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/23 11:19:12 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	ismap(char *str, int i)
{
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'W' && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	check_map_nl(char *str)
{
	int	i;

	i = 0;
	while (!ismap(str, i))
	{
		while (str[i] && str[i] != '\n')
			i++;
		while (str[i] == '\n')
			i++;
	}
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (false);
		i++;
	}
	return (true);
}
