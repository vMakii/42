/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:19:14 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/07 11:39:59 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_signal(t_data *data, int flag)
{
	if (g_sig == SIGINT_HEREDOC || g_sig == SIGINT_BASE_CASE)
		data->exit_status = 130;
	g_sig = flag;
	if (g_sig == BASE_CASE)
		ft_setup_signals();
	else if (g_sig == IN_HEREDOC)
		ft_setup_heredoc_signals();
	else if (g_sig == CHILD)
		ft_setup_child_signals();
	else if (g_sig == IGNORE)
		ft_ignore_signals();
}
