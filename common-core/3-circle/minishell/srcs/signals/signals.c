/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:24:20 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/15 12:43:21 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_sigint_handler(int sig)
{
	(void)sig;
	if (g_sig == IN_HEREDOC)
	{
		g_sig = SIGINT_HEREDOC;
		write(1, "\n", 1);
	}
	else
	{
		g_sig = SIGINT_BASE_CASE;
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_setup_child_signals(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	sigint.sa_handler = SIG_DFL;
	sigquit.sa_handler = SIG_DFL;
	sigemptyset(&sigint.sa_mask);
	sigemptyset(&sigquit.sa_mask);
	sigint.sa_flags = 0;
	sigquit.sa_flags = 0;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
}

void	ft_setup_heredoc_signals(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	sigint.sa_handler = ft_sigint_handler;
	sigquit.sa_handler = SIG_IGN;
	sigemptyset(&sigint.sa_mask);
	sigemptyset(&sigquit.sa_mask);
	sigint.sa_flags = 0;
	sigquit.sa_flags = 0;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
}

void	ft_setup_signals(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	sigint.sa_handler = ft_sigint_handler;
	sigquit.sa_handler = SIG_IGN;
	sigemptyset(&sigint.sa_mask);
	sigemptyset(&sigquit.sa_mask);
	sigint.sa_flags = 0;
	sigquit.sa_flags = 0;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
}

void	ft_ignore_signals(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	sigint.sa_handler = SIG_IGN;
	sigquit.sa_handler = SIG_IGN;
	sigemptyset(&sigint.sa_mask);
	sigemptyset(&sigquit.sa_mask);
	sigint.sa_flags = 0;
	sigquit.sa_flags = 0;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
}
