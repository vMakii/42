/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:56:33 by mivogel           #+#    #+#             */
/*   Updated: 2025/05/05 15:06:58 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_env(char **envp)
{
	int		i;
	int		len;
	char	**env;

	len = 0;
	while (envp[len])
		len++;
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
	ft_update_shlvl(env);
	return (env);
}

void	ft_update_shlvl(char **env)
{
	int		i;
	int		shlvl;
	char	*new_shlvl;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "SHLVL=", 6) == 0)
		{
			shlvl = ft_atoi(env[i] + 6) + 1;
			new_shlvl = ft_strjoin("SHLVL=", ft_itoa(shlvl));
			free(env[i]);
			env[i] = new_shlvl;
			return ;
		}
		i++;
	}
	env[i] = ft_strdup("SHLVL=1");
	env[i + 1] = NULL;
}
