/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:00:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/06/04 14:36:40 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// pid_t	g_pid;

void	ft_init_data(t_data *data, char **env)
{
	data->prompt = NULL;
	data->cmd = NULL;
	data->env = ft_getenv(env);
	if (data->env == NULL)
	{
		perror("ft_env");
		exit(EXIT_FAILURE);
	}
	data->exit = 0;
	data->exit_status = 0;
}

void	ft_test(t_data *data)
{
	t_cmd	*cmd;

	cmd = ft_getcmd(data, BUILTIN);
	if (!cmd)
		return ;
	if (ft_strncmp(cmd->str, "exit", 4) == 0)
		ft_exit(data);
	else if (ft_strncmp(cmd->str, "unset", 5) == 0)
		ft_unset(data);
	else if (ft_strncmp(cmd->str, "env", 3) == 0)
		ft_env(data);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)ac;
	(void)av;
	ft_memset(&data, 0, sizeof(t_data));
	ft_init_data(&data, env);
	while (data.exit == 0)
	{
		data.prompt = readline("\033[0;35mminishell> \033[0m");
		if (!data.prompt)
			break ;
		if (ft_strlen(data.prompt) > 0)
		{
			add_history(data.prompt);
			if (ft_parse(&data))
				ft_test(&data);
		}
		ft_lstprint(data.cmd);
		ft_free(&data);
	}
	rl_clear_history();
	return (data.exit_status);
}
