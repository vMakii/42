/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:43:09 by salsoysa          #+#    #+#             */
/*   Updated: 2025/07/16 09:56:58 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_get_argv_loop(t_cmd *tmp, char **argv)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (tmp->type == CMD || tmp->type == ARG || tmp->type == BUILTIN)
		{
			if (tmp->str && tmp->str[0] != '\0')
			{
				argv[i] = ft_strdup(tmp->str);
				if (!argv[i])
				{
					ft_freetab(argv);
					return (ft_print_error("malloc error"), NULL);
				}
				i++;
			}
		}
		if (tmp->type == PIPE)
			break ;
		tmp = tmp->next;
	}
	argv[i] = NULL;
	return (argv);
}

//					-- Converts cmd lst to an array --
//
// -- Goes through the cmd list until it encounters a PIPE, and for each      //
// -- CMD, ARG, BUILTIN, writes the strings in an array which we return       //
char	**ft_get_argv(t_cmd *cmd)
{
	char	**argv;
	t_cmd	*tmp;

	if (!cmd)
		return (NULL);
	argv = malloc(sizeof(char *) * (ft_lstsize(cmd) + 1));
	if (!argv)
		return (ft_print_error("malloc error"), NULL);
	tmp = cmd;
	ft_get_argv_loop(tmp, argv);
	return (argv);
}

static bool	protect_fd(t_data *data, int fd, char *filename)
{
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		data->exit_status = 1;
		return (false);
	}
	return (true);
}

static bool	ft_handle_redir_utils(t_data *data, t_exec *exec, t_cmd *cmd)
{
	if (cmd->type == IN)
	{
		exec->in = open(cmd->str, O_RDONLY);
		if (!protect_fd(data, exec->in, cmd->str))
			return (false);
		dup2(exec->in, STDIN_FILENO);
		close(exec->in);
	}
	else if (cmd->type == OUT)
	{
		exec->out = open(cmd->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (!protect_fd(data, exec->out, cmd->str))
			return (false);
		dup2(exec->out, STDOUT_FILENO);
		close(exec->out);
	}
	else if (cmd->type == APPEND)
	{
		exec->out = open(cmd->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (!protect_fd(data, exec->out, cmd->str))
			return (false);
		dup2(exec->out, STDOUT_FILENO);
		close(exec->out);
	}
	return (true);
}

void	ft_handle_redir(t_data *data, t_exec *exec, t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == HEREDOC && data->heredoc_fd != -1)
		{
			dup2(data->heredoc_fd, STDIN_FILENO);
			close(data->heredoc_fd);
			data->heredoc_fd = -1;
		}
		if (tmp->type == IN || tmp->type == OUT || tmp->type == APPEND)
		{
			if (!ft_handle_redir_utils(data, exec, tmp))
			{
				ft_free(data, 1);
				exit(EXIT_FAILURE);
			}
		}
		tmp = tmp->next;
	}
}
