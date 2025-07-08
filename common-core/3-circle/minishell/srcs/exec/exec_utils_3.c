/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:12:57 by salsoysa          #+#    #+#             */
/*   Updated: 2025/07/08 12:34:27 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sig_err_print(int err, t_data *data)
{
	if (err == 131)
	{
		ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
		data->exit_status = 131;
	}
	else if (err == 130)
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		data->exit_status = 130;
	}
}

void	ft_wait_for_child(t_pipeline_state *state, t_data *data)
{
	int	status;

	while (state->i < state->nb_pipes)
	{
		waitpid(state->pid[state->i], &status, 0);
		if (WIFSIGNALED(status))
		{
			state->sig = WTERMSIG(status);
			if (state->sig == SIGQUIT)
				ft_sig_err_print(131, data);
			else if (state->sig == SIGINT)
				ft_sig_err_print(130, data);
			else
				data->exit_status = 128 + state->sig;
		}
		else if (WIFEXITED(status))
		{
			if (state->i == state->nb_pipes - 1)
				data->exit_status = WEXITSTATUS(status);
		}
		state->i++;
	}
}

void	ft_parent_process(t_pipeline_state *state, t_cmd **cmd)
{
	close_pipedfds(state->pipefd[1], -1);
	if (state->i != 0)
		close(state->old_fd);
	state->old_fd = state->pipefd[0];
	ft_next_segment(cmd);
	state->i++;
}

void	ft_child_process(t_pipeline_state *state, t_cmd *cmd, t_exec *exec,
		t_data *data)
{
	ft_set_signal(data, CHILD);
	if (state->i != state->nb_pipes - 1)
		dup2(state->pipefd[1], STDOUT_FILENO);
	if (state->i != 0)
	{
		dup2(state->old_fd, STDIN_FILENO);
		close(state->old_fd);
	}
	close_pipedfds(state->pipefd[0], state->pipefd[1]);
	ft_handle_redir(data, exec, cmd);
	ft_exec_cmd(data, cmd);
	exit(EXIT_FAILURE);
}
