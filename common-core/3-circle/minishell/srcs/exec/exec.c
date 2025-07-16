/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:46:18 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/16 17:14:18 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_builtin(t_data *data, t_cmd *cmd, char **argv)
{
	if (ft_strncmp(cmd->str, "cd", 2) == 0)
		data->exit_status = ft_cd(argv, data);
	else if (ft_strncmp(cmd->str, "echo", 4) == 0)
		data->exit_status = ft_echo(argv);
	else if (ft_strncmp(cmd->str, "env", 3) == 0)
		data->exit_status = ft_env(data);
	else if (ft_strncmp(cmd->str, "exit", 4) == 0)
		ft_exit(data);
	else if (ft_strncmp(cmd->str, "export", 6) == 0)
		data->exit_status = ft_export(argv, data);
	else if (ft_strncmp(cmd->str, "pwd", 3) == 0)
		data->exit_status = ft_pwd();
	else if (ft_strncmp(cmd->str, "unset", 5) == 0)
		data->exit_status = ft_unset(data);
}

static void	ft_prepare_exec_builtin(t_data *data, t_exec *exec)
{
	t_cmd	*cmd;
	char	**argv;

	cmd = ft_getcmd(data, BUILTIN);
	argv = ft_get_argv(cmd);
	if (!argv || !argv[0])
	{
		ft_freetab(argv);
		return ;
	}
	if (!cmd)
		return ;
	exec->saved_stdin = dup(STDIN_FILENO);
	exec->saved_stdout = dup(STDOUT_FILENO);
	ft_handle_redir(data, exec, data->cmd);
	ft_exec_builtin(data, cmd, argv);
	dup2(exec->saved_stdout, STDOUT_FILENO);
	dup2(exec->saved_stdin, STDIN_FILENO);
	close(exec->saved_stdout);
	close(exec->saved_stdin);
	ft_freetab(argv);
}

void	ft_exec(t_data *data)
{
	t_cmd	*cmd;
	t_cmd	*builtin;
	t_exec	exec;
	int		nb_pipes;

	ft_memset(&exec, 0, sizeof(t_exec));
	cmd = ft_getcmd(data, CMD);
	builtin = ft_getcmd(data, BUILTIN);
	if (!cmd && !builtin)
		return ;
	nb_pipes = ft_getnb_pipe(data);
	if (nb_pipes < 0)
	{
		data->exit_status = 1;
		return ;
	}
	if (builtin && !nb_pipes)
	{
		ft_prepare_exec_builtin(data, &exec);
		return ;
	}
	else
		ft_exec_pipeline(data, data->cmd, &exec);
}

void	ft_exec_pipeline(t_data *data, t_cmd *cmd, t_exec *exec)
{
	t_pipeline_state	st;

	init_pipeline_state(data, &st);
	while (cmd)
	{
		if (!ft_pipe(cmd, st.pipefd))
			return ;
		st.pid[st.i] = fork();
		if (st.pid[st.i] < 0)
		{
			perror("minishell: fork");
			ft_free(data, 1);
			exit(EXIT_FAILURE);
		}
		else if (st.pid[st.i] == 0)
			ft_child_process(&st, cmd, exec, data);
		else
			ft_parent_process(&st, &cmd);
	}
	close_pipedfds(st.pipefd[0], -1);
	ft_set_signal(data, IGNORE);
	st.i = 0;
	ft_wait_for_child(&st, data);
	ft_set_signal(data, BASE_CASE);
}

void	ft_exec_cmd(t_data *data, t_cmd *cmd)
{
	t_exec	exec;
	char	**argv;

	argv = ft_get_argv(cmd);
	if (!argv)
		return ;
	if (cmd->type == BUILTIN)
	{
		ft_exec_builtin(data, cmd, argv);
		_free_utils(argv, data, 1);
		exit(data->exit_status);
	}
	exec.cmd = get_command_path(argv[0], data);
	if (!exec.cmd)
	{
		_free_utils(argv, data, 1);
		exit(data->exit_status);
	}
	if (execve(exec.cmd, argv, data->env) == -1)
	{
		perror("minishell");
		free(exec.cmd);
		_free_utils(argv, data, 1);
		exit(EXIT_FAILURE);
	}
}
