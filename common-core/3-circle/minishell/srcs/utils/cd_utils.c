/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:09:23 by salsoysa          #+#    #+#             */
/*   Updated: 2025/07/03 14:49:12 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_env_existing(t_data *data, int var_i, char *new_var)
{
	free(data->env[var_i]);
	data->env[var_i] = new_var;
}

static void	update_env_new(t_data *data, char *new_var)
{
	char	**new_env;
	int		i;

	new_env = malloc(sizeof(char *) * (env_size(data->env) + 2));
	if (!new_env)
	{
		free(new_var);
		return ;
	}
	i = 0;
	while (data->env[i])
	{
		new_env[i] = data->env[i];
		i++;
	}
	new_env[i] = new_var;
	new_env[i + 1] = NULL;
	free(data->env);
	data->env = new_env;
}

void	update_env_var(t_data *data, const char *var_name, const char *value)
{
	int		var_i;
	char	*new_var;
	char	*temp;

	var_i = var_index(data->env, var_name);
	temp = ft_strjoin(var_name, "=");
	if (!temp)
		return ;
	new_var = ft_strjoin(temp, value);
	free(temp);
	if (!new_var)
		return ;
	if (var_i != -1)
		update_env_existing(data, var_i, new_var);
	else
		update_env_new(data, new_var);
}
