/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:22:50 by salsoysa          #+#    #+#             */
/*   Updated: 2025/06/23 11:24:52 by akaiissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
static char	*find_cmd_dir(char *cmd, char **exec_dir)
{
	int		i;
	char	*cmd_d;

	cmd_d = NULL;
	i = 0;
	while (exec_dir[i])
	{
		cmd_d = ft_strjoin(exec_dir[i], cmd);
		if (!cmd_d)
		{
			ft_freetab(exec_dir);
			// error malloc error while checking cmd path;
		}
		if (access(cmd_d, F_OK | X_OK) == 0)
			return (cmd_d);
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
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	exec_dir = split_path(data->env);
	if (!exec_dir)
		return (NULL);
	cmd_d = find_cmd_dir(cmd, exec_dir);
	if (!cmd_d)
	{
		// error Command not found: cmd, exit status 127
		data->exit_status = 127;
		return (NULL);
	}
	ft_freetab(exec_dir);
	return (cmd_d);
}
