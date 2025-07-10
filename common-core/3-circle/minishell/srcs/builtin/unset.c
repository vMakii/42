/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:06:54 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/10 13:45:16 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset_utils(t_data *data, char *str)
{
	int	i;
	int	len;

	if (!data || !data->env || !str || !*str)
		return ;
	i = 0;
	len = ft_strlen(str);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], str, len) == 0 && data->env[i][len] == '=')
		{
			free(data->env[i]);
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

int	ft_unset(t_data *data)
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
	return (0);
}
