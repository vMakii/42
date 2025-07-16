/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:22:50 by salsoysa          #+#    #+#             */
/*   Updated: 2025/07/16 13:09:33 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <asm-generic/errno-base.h>
#include <dirent.h>

// Searching for "PATH=" in environnement, when found, returns a string with
// everything after the "=" sign, to get the needed directories
static char	*find_path(char **env)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (env[i] != NULL && env[i][0] != '\0')
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		if (path)
		{
			path = ft_substr(path, 5, ft_strlen(path));
			break ;
		}
		i++;
	}
	return (path);
}

// Formats the splited directory paths, adding a "/" at the end so we can
// later join the cmd name, and try and execute the command
static char	**format_path_to_exec(char **paths)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(tmp);
		i++;
	}
	return (paths);
}

// Splits the path when ":" is found, so we have a tab with every directory
// containing the executable commands.
static char	**split_path(char **env)
{
	char	*env_str;
	char	**exec_dir;

	env_str = find_path(env);
	if (!env_str)
		return (NULL);
	exec_dir = ft_split(env_str, ':');
	free(env_str);
	if (!exec_dir)
		return (NULL);
	exec_dir = format_path_to_exec(exec_dir);
	if (!exec_dir)
		return (NULL);
	return (exec_dir);
}

// Joins cmd with previously found paths, and returns the first executable path
static char	*find_cmd_dir(char *cmd, char **exec_dir, t_data *data)
{
	int		i;
	char	*cmd_d;

	cmd_d = NULL;
	i = 0;
	data->exit_status = 127;
	while (exec_dir[i])
	{
		cmd_d = ft_strjoin(exec_dir[i], cmd);
		if (!cmd_d)
			return (ft_freetab(exec_dir), NULL);
		if (access(cmd_d, F_OK) == 0)
		{
			if (access(cmd_d, X_OK) == 0)
				return (ft_freetab(exec_dir), cmd_d);
			data->exit_status = 126;
			free(cmd_d);
			break ;
		}
		free(cmd_d);
		i++;
	}
	ft_freetab(exec_dir);
	return (NULL);
}

// Checks if "cmd" is executable, if not, checks if we can find the executable
// path and returns it
char	*get_command_path(char *cmd, t_data *data)
{
	char	**exec_dir;
	char	*cmd_d;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (_access_check(cmd, data));
	exec_dir = split_path(data->env);
	if (!exec_dir)
	{
		data->exit_status = 127;
		printf("minishell: %s: No such file of directory\n", cmd);
		return (NULL);
	}
	cmd_d = find_cmd_dir(cmd, exec_dir, data);
	if (!cmd_d)
	{
		if (data->exit_status == 126)
			printf("minishell: %s: Permission denied\n", cmd);
		else
			printf("minishell: %s: command not found\n", cmd);
	}
	return (cmd_d);
}
