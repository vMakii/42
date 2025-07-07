/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:11:23 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/07 13:53:58 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	overflow(char *str, unsigned long long *nbr, unsigned long long max)
{
	unsigned long long	remaining;
	unsigned long long	next;

	next = *str - '0';
	if (*nbr > 922337203685477580ULL || *nbr * 10 > max)
		return (0);
	remaining = max - (*nbr * 10);
	if (next > remaining)
		return (0);
	remaining -= next;
	*nbr = *nbr * 10 + next;
	return (1);
}

static int	ft_atoll_exitcode(char *str, unsigned char *status)
{
	unsigned long long	res;
	long long			sign;

	if (!str || !*str)
		return (0);
	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		if (sign == 1 && !overflow(str, &res, POSITIVE_MAX))
			return (0);
		else if (sign == -1 && !overflow(str, &res, NEGATIVE_MAX))
			return (0);
		str++;
	}
	if (*str)
		return (0);
	*status = (unsigned char)((long long)res * sign);
	return (1);
}

static bool	exit_utils(t_data *data, t_cmd *tmp)
{
	unsigned char	status;

	status = data->exit_status;
	if (tmp->type == ARG)
	{
		if (!ft_atoll_exitcode(tmp->str, &status))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(tmp->str, 2);
			ft_putstr_fd(" : numeric argument required\n", 2);
			data->exit_status = 2;
			data->exit = 1;
			return (true);
		}
	}
	if (tmp->type == ARG && tmp->next && tmp->next->next
		&& tmp->next->next->type == ARG)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		data->exit_status = 1;
		return (true);
	}
	data->exit_status = status;
	return (false);
}

void	ft_exit(t_data *data)
{
	t_cmd	*tmp;

	tmp = data->cmd;
	if (is_tty())
		ft_putstr_fd("exit\n", 1);
	while (tmp)
	{
		if (exit_utils(data, tmp))
			return ;
		tmp = tmp->next;
	}
	data->exit = 1;
}
