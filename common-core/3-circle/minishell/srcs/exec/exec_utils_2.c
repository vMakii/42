/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:05:14 by salsoysa          #+#    #+#             */
/*   Updated: 2025/07/05 20:29:38 by salsoysa         ###   ########.fr       */
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
//	printf("%s", (*cmd)->str);
}
