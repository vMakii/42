/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:06:54 by mivogel           #+#    #+#             */
/*   Updated: 2025/06/03 15:08:26 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset_utils(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (ft_strnstr(data->env[i], str, ft_strlen(str)) == data->env[i])
		{
			free(data->env[i]);
			data->env[i] = NULL;
			while (data->env[i + 1])
			{
				data->env[i] = data->env[i + 1];
				i++;
			}
			data->env[i] = NULL;
			break ;
		}
		i++;
	}
}

void	ft_unset(t_data *data)
{
	t_cmd	*tmp;

	tmp = data->cmd;
	while (tmp)
	{
		if (tmp->type == ARG)
		{
			unset_utils(data, tmp->str);
		}
		tmp = tmp->next;
	}
}
