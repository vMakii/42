/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:45:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/08 11:59:12 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_saved_pwd(t_data *data, char *current_dir)
{
	char	*saved_pwd;

	saved_pwd = NULL;
	if (getcwd(current_dir, PATH_MAX))
		saved_pwd = current_dir;
	else
	{
		saved_pwd = get_env_value(data->env, "PWD");
		if (!saved_pwd)
			ft_print_error("cd: warning: current directory removed");
	}
	return (saved_pwd);
}

static char	*get_target_path(char **args, t_data *data)
{
	char	*target_path;

	if (!args[1] || args[1][0] == '~')
	{
		target_path = get_env_value(data->env, "HOME");
		if (target_path[0] == '\0')
		{
			ft_print_error("cd: HOME not set");
			return (NULL);
		}
	}
	else if (ft_strncmp(args[1], "-", 2) == 0)
	{
		target_path = get_env_value(data->env, "OLDPWD");
		if (target_path[0] == '\0')
		{
			ft_print_error("cd: OLDPWD not set");
			return (NULL);
		}
		ft_putstr_fd(target_path, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		target_path = args[1];
	return (target_path);
}

static int	change_directory(char *target_path)
{
	char	*temp;

	if (chdir(target_path) == -1)
	{
		temp = ft_strjoin("cd: ", target_path);
		if (temp)
		{
			ft_print_error(temp);
			free(temp);
		}
		else
			ft_print_error("cd: failed to change directory");
		return (1);
	}
	return (0);
}

static void	update_pwd_vars(t_data *data, char *saved_pwd)
{
	char	current_dir[PATH_MAX];

	if (saved_pwd)
		update_env_var(data, "OLDPWD", saved_pwd);
	if (getcwd(current_dir, PATH_MAX))
		update_env_var(data, "PWD", current_dir);
}

int	ft_cd(char **args, t_data *data)
{
	char	*target_path;
	char	current_dir[PATH_MAX];
	char	*saved_pwd;

	saved_pwd = get_saved_pwd(data, current_dir);
	target_path = get_target_path(args, data);
	if (!target_path)
		return (1);
	if (change_directory(target_path))
		return (1);
	update_pwd_vars(data, saved_pwd);
	return (0);
}
