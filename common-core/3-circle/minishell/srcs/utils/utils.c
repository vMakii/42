/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:44:43 by salsoysa          #+#    #+#             */
/*   Updated: 2025/06/03 13:16:44 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_getnb_arg(t_cmd *cmd)
{
	int		nb_arg;
	t_cmd	*tmp;

	nb_arg = 0;
	tmp = cmd;
	while (tmp)
	{
		if (tmp->type == ARG)
			nb_arg++;
		tmp = tmp->next;
	}
	return (nb_arg);
}

char	**dup_env(char **envp)
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
	return (env);
}

// ptet je peux faire sans
static void	swap_arr(int i, int j, char **arr)
{
	char	*tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void	sort_arr(char **envp, int len)
{
	int	i;
	int	j;
	int	sort;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			sort = ft_strncmp(envp[i], envp[j], INT_MAX);
			if (sort > 0)
			{
				swap_arr(i, j, envp);
				continue ;
			}
			j++;
		}
		i++;
	}
}

int	env_size(char **envp)
{
	int	i;

	if (!envp)
		return (0);
	i = 0;
	while (envp[i])
		i++;
	return (i);
}
