/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:05:14 by salsoysa          #+#    #+#             */
/*   Updated: 2025/07/09 18:52:50 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// fonction next_segment(cmd):
//     avancer cmd jusqu’au prochain PIPE
//     puis avancer encore d’un pour passer au début du prochain segment
//     retourner ce nouveau cmd
void	ft_next_segment(t_cmd **cmd)
{
	while (*cmd && (*cmd)->type != PIPE)
		*cmd = (*cmd)->next;
	if (*cmd)
		*cmd = (*cmd)->next;
	while (*cmd && (*cmd)->type == SPC)
		*cmd = (*cmd)->next;
}

void	init_pipeline_state(t_data *data, t_pipeline_state *state)
{
	state->i = 0;
	state->pipefd[0] = -1;
	state->pipefd[1] = -1;
	state->nb_pipes = ft_getnb_pipe(data) + 1;
	state->old_fd = -1;
	state->sig = -1;
}

void	close_pipedfds(int pipefd1, int pipefd2)
{
	if (pipefd1 >= 0)
		close(pipefd1);
	if (pipefd2 >= 0)
		close(pipefd2);
}

bool	ft_pipe(t_cmd *cmd, int *pipefd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp && tmp->type != PIPE)
		tmp = tmp->next;
	if (tmp && tmp->type == PIPE)
	{
		if (pipe(pipefd) < 0)
		{
			perror("minishell: pipe");
			return (false);
		}
	}
	return (true);
}
