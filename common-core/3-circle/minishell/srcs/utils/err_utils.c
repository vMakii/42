/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:15:34 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/15 13:03:43 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(t_data *data, int end)
{
	if (data->prompt)
	{
		free(data->prompt);
		data->prompt = NULL;
	}
	ft_lstclear(&data->cmd);
	data->cmd = NULL;
	if (data->heredoc_fd != -1)
	{
		close(data->heredoc_fd);
		data->heredoc_fd = -1;
	}
	if (data->env && end)
	{
		ft_freetab(data->env);
		data->env = NULL;
		get_next_line(0, 1);  // Free static buffer in get_next_line
	}
}

bool	is_tty(void)
{
	return (isatty(STDIN_FILENO));
}

void	ft_print_error(char *msg)
{
	if (msg)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		if (errno)
		{
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putstr_fd(strerror(errno), STDERR_FILENO);
		}
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}
