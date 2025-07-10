/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:56:11 by salsoysa          #+#    #+#             */
/*   Updated: 2025/07/09 18:17:02 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_no_args(char **env)
{
	int		i;
	int		j;
	char	**envcp;

	envcp = dup_env(env);
	if (!envcp)
		return ;
	sort_arr(env, env_size(envcp));
	i = 0;
	while (env[i])
	{
		printf("export ");
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			printf("%c", env[i][j++]);
		if (env[i][j] && env[i][j] == '=')
			printf("=\"%s\"\n", &env[i][j + 1]);
		else
			printf("\n");
		i++;
	}
	ft_freetab(envcp);
}

int	check_arg(char *str)
{
	int	i;

	i = 0;
	if (!str[0] || (str[0] != '_' && !ft_isalpha(str[0])))
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	var_index(char **env, const char *var)
{
	int	i;
	int	len;

	len = 0;
	while (var[len] && var[len] != '=')
		len++;
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, len))
			if (env[i][len] == '=' || env[i][len] == '\0')
				return (i);
		i++;
	}
	return (-1);
}

int	export(char ***env, char *str)
{
	int		index;
	int		i;
	char	**update;

	index = var_index(*env, str);
	if (index >= 0)
	{
		free((*env)[index]);
		(*env)[index] = ft_strdup(str);
	}
	else
	{
		update = malloc(sizeof(char *) * (env_size(*env) + 2));
		if (!update)
			return (0);
		i = -1;
		while (++i < env_size(*env))
			update[i] = (*env)[i];
		update[i++] = ft_strdup(str);
		update[i] = NULL;
		free(*env);
		(*env) = update;
	}
	return (1);
}

int	ft_export(char **args, t_data *data)
{
	int	exit_code;
	int	i;

	i = 1;
	exit_code = 0;
	if (!args[i])
	{
		print_no_args(data->env);
		return (0);
	}
	while (args[i])
	{
		if (!check_arg(args[i]))
		{
			ft_putstr_fd("export: not a valid identifier\n", 2);
			exit_code = 1;
		}
		else if (!export(&data->env, args[i]))
			return (printf("ERROR_MALLOC\n"));
		i++;
	}
	return (exit_code);
}
