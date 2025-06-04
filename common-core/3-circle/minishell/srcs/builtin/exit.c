/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:11:23 by mivogel           #+#    #+#             */
/*   Updated: 2025/06/03 15:08:41 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	exit_utils(t_data *data, t_cmd *tmp)
{
	if (tmp->type == ARG && !tmp->next)
	{
		data->exit_status = ft_atoi(tmp->str);
		data->exit = 1;
		return (true);
	}
	if (tmp->type == ARG && !ft_isnum(tmp->str))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(tmp->str, 2);
		ft_putstr_fd(" : numeric argument required\n", 2);
		data->exit_status = 2;
		data->exit = 1;
		return (true);
	}
	if (tmp->type == ARG && tmp->next->next && tmp->next->next->type == ARG)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		data->exit_status = 1;
		return (true);
	}
	return (false);
}

void	ft_exit(t_data *data)
{
	t_cmd	*tmp;

	tmp = data->cmd;
	ft_putstr_fd("exit\n", 1);
	while (tmp)
	{
		if (exit_utils(data, tmp))
			return ;
		tmp = tmp->next;
	}
	data->exit = 1;
}
