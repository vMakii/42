/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:56:33 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/09 17:41:07 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_var_len(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '?')
		return (1);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
}

char	*get_env_value(char **env, const char *name)
{
	int		i;
	size_t	len;

	i = 0;
	len = get_var_len(name);
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], name, len) && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return ("");
}

static char	**ft_gen_env(void)
{
	char	**env;
	char	cwd[PATH_MAX];

	env = malloc(sizeof(char *) * 4);
	if (!env)
		return (NULL);
	env[0] = ft_strjoin("PWD=", ft_strdup(getcwd(cwd, PATH_MAX)));
	env[1] = ft_strdup("SHLVL=0");
	env[2] = ft_strdup("_=/usr/bin/env");
	env[3] = NULL;
	return (env);
}

static void	ft_update_shlvl(char **env)
{
	int		i;
	char	*shlvl;
	char	*new_shlvl;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "SHLVL=", 6) == 0)
		{
			shlvl = ft_itoa(ft_atoi(env[i] + 6) + 1);
			new_shlvl = ft_strjoin("SHLVL=", shlvl);
			if (!new_shlvl)
				return (free(shlvl));
			free(env[i]);
			free(shlvl);
			env[i] = new_shlvl;
			return ;
		}
		i++;
	}
	env[i] = ft_strdup("SHLVL=1");
	env[i + 1] = NULL;
}

char	**ft_getenv(char **envp)
{
	int		i;
	int		len;
	char	**env;

	len = 0;
	while (envp[len])
		len++;
	if (len == 0)
		env = ft_gen_env();
	else
	{
		env = malloc(sizeof(char *) * (len + 1));
		if (!env)
			return (NULL);
		i = 0;
		while (envp[i])
		{
			env[i] = ft_strdup(envp[i]);
			i++;
		}
		env[i] = NULL;
	}
	ft_update_shlvl(env);
	return (env);
}
