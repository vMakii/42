/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:46:18 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/07 13:54:02 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_builtin(t_data *data)
{
	t_cmd	*cmd;
	char	**argv;

	cmd = ft_getcmd(data, BUILTIN);
	argv = ft_get_argv(cmd);
	if (!cmd)
		return ;
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
	ft_freetab(argv);
}

// Exec part 1
// fonction ft_exec(data):
//     si pas de commande :
//         return

//     si c'est une commande BUILTIN et qu'il n'y a pas de PIPE :
//         exécuter directement le builtin (sans fork)
//         return

//     exécuter le pipeline complet :
//         exec_pipeline(data, data->cmd)
void	ft_exec(t_data *data)
{
	t_cmd	*cmd;
	t_cmd	*builtin;

	cmd = ft_getcmd(data, CMD);
	builtin = ft_getcmd(data, BUILTIN);
	if (!cmd && !builtin)
		return ;
	if (builtin && !ft_getnb_pipe(data))
	{
		ft_exec_builtin(data);
		return ;
	}
	else
		ft_exec_pipeline(data, data->cmd);
}
// ---

// fonction exec_pipeline(data, cmd):
//     prev_fd = -1  // utilisé pour relier le pipe précédent

//     TANT QU'il reste des commandes à exécuter :
//         si une PIPE suit cette commande :
//             créer un nouveau pipe : pipe_fd[0] (lecture),
// pipe_fd[1] (écriture)
//         sinon :
//             pipe_fd[1] = -1 (pas de sortie à rediriger)

//         forker un processus

//         SI processus enfant :
//             si prev_fd est valide :
//                 dup2(prev_fd, STDIN)
//                 fermer prev_fd

//             si pipe_fd[1] est valide :
//                 dup2(pipe_fd[1], STDOUT)
//                 fermer pipe_fd[1]
//                 fermer pipe_fd[0] (inutile dans le fils)

//             gérer les redirections éventuelles (<, >, >>)
//             transformer les tokens en tableau d'arguments
//             trouver le chemin via PATH ou l'utiliser directement
//             execve(path, args, env)
//             si execve échoue : perror + exit
// SINON si processus parent :
//             si prev_fd est valide :
//                 fermer prev_fd

//             si pipe_fd[1] est valide :
//                 fermer pipe_fd[1] (car plus besoin d’écrire dans ce pipe)

//             prev_fd = pipe_fd[0]
// garder la lecture pour la prochaine commande

//         avancer cmd au prochain segment (juste après le PIPE)

//     attendre tous les processus avec wait
//     mettre à jour data->exit_status avec le statut du dernier processus
void	close_pipedfds(int pipefd1, int pipefd2)
{
	if (pipefd1 >= 0)
		close(pipefd1);
	if (pipefd2 >= 0)
		close(pipefd2);
}

void	ft_exec_pipeline(t_data *data, t_cmd *cmd)
{
	t_exec				exec;
	int					status;
	t_pipeline_state	state;

	state.i = 0;
	state.pipefd[0] = -1;
	state.pipefd[1] = -1;
	state.nb_pipes = ft_getnb_pipe(data) + 1;
	state.old_fd = -1;
	while (cmd)
	{
		if (cmd->next && cmd->next->next)
		{
			if (pipe(state.pipefd) == -1)
			{
				perror("minishell: pipe");
				exit(EXIT_FAILURE);
			}
		}
		state.pid[state.i] = fork();
		if (state.pid[state.i] == -1)
		{
			perror("minishell: fork");
			exit(EXIT_FAILURE);
		}
		else if (state.pid[state.i] == 0)
		{
			ft_set_signal(data, CHILD);
			if (state.i != state.nb_pipes - 1)
				dup2(state.pipefd[1], STDOUT_FILENO);
			if (state.i != 0)
			{
				dup2(state.old_fd, STDIN_FILENO);
				close(state.old_fd);
			}
			close_pipedfds(state.pipefd[0], state.pipefd[1]);
			//			close(state.pipefd[0]);
			//			close(state.pipefd[1]);
			ft_handle_redir(data, &exec, cmd);
			ft_exec_cmd(data, cmd);
			exit(EXIT_FAILURE);
		}
		else
		{
			close_pipedfds(state.pipefd[1], -1);
			//			close(state.pipefd[1]);
			if (state.i != 0)
				close(state.old_fd);
			state.old_fd = state.pipefd[0];
			ft_next_segment(&cmd);
		}
		state.i++;
	}
	close_pipedfds(state.pipefd[0], -1);
	ft_set_signal(data, IGNORE);
	state.i = 0;
	while (state.i < state.nb_pipes)
	{
		waitpid(state.pid[state.i], &status, 0);
		if (WIFSIGNALED(status))
		{
			state.sig = WTERMSIG(status);
			if (state.sig == SIGQUIT)
			{
				ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
				data->exit_status = 131;
			}
			else if (state.sig == SIGINT)
			{
				ft_putstr_fd("\n", STDERR_FILENO);
				data->exit_status = 130;
			}
			else
			{
				data->exit_status = 128 + state.sig;
			}
		}
		else if (WIFEXITED(status))
		{
			// Only set exit status from the last process in the pipeline
			if (state.i == state.nb_pipes - 1)
				data->exit_status = WEXITSTATUS(status);
		}
		state.i++;
	}
	ft_set_signal(data, BASE_CASE);
}

// fonction execute_command(data, cmd):
//     gérer redirections (<, >, >>)
//     convertir la liste chaînée cmd en tableau d'arguments
//     trouver le chemin via PATH
//     execve(path, args, env)
void	ft_exec_cmd(t_data *data, t_cmd *cmd)
{
	t_exec	exec;
	char	**argv;

	ft_handle_redir(data, &exec, cmd);
	argv = ft_get_argv(cmd);
	exec.cmd = get_command_path(argv[0], data);
	// if (!exec.cmd)
	// { // a voir pour les msg d'erreurs
	// 	ft_putstr_fd("minishell: command not found: ", STDERR_FILENO);
	// 	ft_putstr_fd(argv[0], STDERR_FILENO);
	// 	ft_putstr_fd("\n", STDERR_FILENO);
	// 	free(argv);
	// 	return ;
	// }
	if (execve(exec.cmd, argv, data->env) == -1)
	{
		perror("minishell");
		exit(EXIT_FAILURE);
	}
}
