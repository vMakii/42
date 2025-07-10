/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:58:29 by salsoysa          #+#    #+#             */
/*   Updated: 2025/07/09 20:34:36 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	_is_dir(char *cmd, t_data *data)
{
	DIR	*d;

	d = opendir(cmd);
	if (d)
	{
		closedir(d);
		printf("minishell: is a directory: %s\n", cmd);
		data->exit_status = 126;
		return (false);
	}
	else if (errno != ENOTDIR)
	{
		perror(cmd);
		data->exit_status = 126;
		return (false);
	}
	return (true);
}

char	*_access_check(char *cmd, t_data *data)
{
	if (access(cmd, F_OK) != 0)
	{
		printf("minishell: %s: No such file or directory\n", cmd);
		data->exit_status = 127;
		return (NULL);
	}
	if (!_is_dir(cmd, data))
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	printf("minishell: permission denied: %s\n", cmd);
	data->exit_status = 126;
	return (NULL);
}
