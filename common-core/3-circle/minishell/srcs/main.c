/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:00:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/10 14:15:24 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sig = BASE_CASE;

void	ft_init_data(t_data *data, int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	ft_set_signal(data, BASE_CASE);
	data->prompt = NULL;
	data->cmd = NULL;
	data->env = ft_getenv(env);
	if (data->env == NULL)
	{
		perror("ft_env");
		exit(EXIT_FAILURE);
	}
	data->heredoc_i = 0;
	data->heredoc_fd = -1;
	data->exit = 0;
	data->exit_status = 0;
}

static char	*read_tty_input(void)
{
	char	*input;

	if (isatty(STDOUT_FILENO))
		input = readline(PROMPT_COLOR PROMPT_TEXT PROMPT_RESET);
	else
		input = readline("minishell> ");
	if (input == NULL)
		ft_putstr_fd("exit\n", 2);
	else if (ft_strlen(input) > 0)
		add_history(input);
	return (input);
}

static char	*read_non_tty_input(void)
{
	char	*input;

	input = get_next_line(STDIN_FILENO, 0);
	if (input && input[ft_strlen(input) - 1] == '\n')
		input[ft_strlen(input) - 1] = '\0';
	return (input);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	ft_init_data(&data, ac, av, env);
	while (data.exit == 0)
	{
		if (is_tty())
			data.prompt = read_tty_input();
		else
			data.prompt = read_non_tty_input();
		if (data.prompt == NULL)
			break ;
		ft_set_signal(&data, BASE_CASE);
		if (ft_strlen(data.prompt) > 0 && ft_strlen(data.prompt) < INPUT_SIZE)
		{
			if (ft_parse(&data))
				if (ft_prepare_heredocs(&data))
					ft_exec(&data);
		}
		ft_free(&data, 0);
	}
	rl_clear_history();
	ft_free(&data, 1);
	return (data.exit_status);
}
