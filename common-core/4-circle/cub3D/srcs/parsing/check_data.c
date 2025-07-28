/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gburtin <gburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:07:59 by gburtin           #+#    #+#             */
/*   Updated: 2025/07/27 13:12:53 by gburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_order(char **tab)
{
	int	len;
	int	i;

	len = 0;
	while (tab[len])
		len++;
	i = 0;
	while (tab[len - 1][i])
	{
		if (tab[len - 1][i] != '1' && tab[len - 1][i] != ' '
			&& tab[len - 1][i] != '0')
			return (false);
		i++;
	}
	return (true);
}

bool	check_textures(char **tab)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (tab[i] && ft_strlen(tab[i]) >= 3)
	{
		if ((!ft_strncmp(tab[i], "NO", 2) || !ft_strncmp(tab[i], "SO", 2)
				|| !ft_strncmp(tab[i], "WE", 2) || !ft_strncmp(tab[i], "EA", 2))
			&& tab[i][2] == ' ')
		{
			if (ft_count_word(tab[i], ' ') != 2)
				return (false);
			count++;
		}
		i++;
	}
	if (count == 4)
		return (true);
	return (false);
}

int	check_colors_2(char *str)
{
	int	j;
	int	count;
	int	len;

	count = 0;
	j = 1;
	while (str[j])
	{
		if (str[j] != ' ' && !ft_isdigit(str[j]) && str[j] != ',')
			return (0);
		if (ft_isdigit(str[j]) && !ft_isdigit(str[j - 1]))
		{
			count++;
			while (str[j] == '0')
				j++;
			len = j;
			while (str[len] && ft_isdigit(str[len]))
				len++;
			if (len - j > 3)
				return (0);
		}
		j++;
	}
	return (count);
}

bool	check_colors(char **tab, char *id)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (tab[i] && ft_strlen(tab[i]) >= 2)
	{
		if (!ft_strncmp(tab[i], id, 1) && tab[i][1] == ' ') // add whitespace 
		{
			if (check_colors_2(tab[i]) != 3)
				return (false);
			count++;
		}
		i++;
	}
	if (count == 1)
		return (true);
	return (false);
}

bool	check_data(t_data *data)
{
	if (check_order(data->map.tab) == false)
		return (printf("order\n"), false);
	if (check_textures(data->map.tab) == false)
		return (printf("textures\n"), false);
	if (check_colors(data->map.tab, "F") == false)
		return (printf("color F\n"), false);
	if (check_colors(data->map.tab, "C") == false)
		return (printf("color C\n"), false);
	return (true);
}
