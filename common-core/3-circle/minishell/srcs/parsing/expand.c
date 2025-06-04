/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:08:41 by mivogel           #+#    #+#             */
/*   Updated: 2025/06/04 14:46:58 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_var_len(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '?')
		return (1);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
}

static char	*get_env_value(char **env, const char *name)
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

static int	ft_expand_len(t_data *data, const char *str)
{
	int	i;
	int	len;
	int	in_sgl;

	i = 0;
	len = 0;
	in_sgl = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			in_sgl = !in_sgl;
		else if (str[i] == '$' && !in_sgl)
		{
			len += ft_strlen(get_env_value(data->env, str + i + 1));
			i += get_var_len(str + i + 1);
		}
		len++;
		i++;
	}
	return (len);
}

static	expand_utils(void)
{
	if (str[i] == '$' && !in_sgl)
	{
		i++;
		if (str[i] == '\0')
			exp[j++] = '$';
		else if (ft_strncmp(str + i, "?", 1) == 0)
		{
			env_value = ft_itoa(data->exit_status);
			k = 0;
			while (env_value[k])
				exp[j++] = env_value[k++];
			i++;
			free(env_value);
		}
		else
		{
			k = 0;
			var_len = ft_strlen(get_env_value(data->env, str + i));
			env_value = get_env_value(data->env, str + i);
			if (var_len == 0)
				exp[j++] = '\0';
			else
			{
				while (env_value[k])
					exp[j++] = env_value[k++];
			}
			i += get_var_len(str + i);
		}
	}
}

char	*ft_expand(t_data *data, char *str)
{
	int		i;
	int		j;
	int		k;
	int		len;
	int		in_sgl;
	char	*exp;
	char	*env_value;
	int		var_len;
	else	exp[j++] = str[i++];

	i = 0;
	j = 0;
	in_sgl = 0;
	len = ft_expand_len(data, str);
	exp = malloc(len + 1);
	if (!exp)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\'')
			in_sgl = !in_sgl;
		expand_utils();
		// if (str[i] == '$' && !in_sgl)
		// {
		// 	i++;
		// 	if (str[i] == '\0')
		// 		exp[j++] = '$';
		// 	else if (ft_strncmp(str + i, "?", 1) == 0)
		// 	{
		// 		env_value = ft_itoa(data->exit_status);
		// 		k = 0;
		// 		while (env_value[k])
		// 			exp[j++] = env_value[k++];
		// 		i++;
		// 		free(env_value);
		// 	}
		// 	else
		// 	{
		// 		k = 0;
		// 		var_len = ft_strlen(get_env_value(data->env, str + i));
		// 		env_value = get_env_value(data->env, str + i);
		// 		if (var_len == 0)
		// 			exp[j++] = '\0';
		// 		else
		// 		{
		// 			while (env_value[k])
		// 				exp[j++] = env_value[k++];
		// 		}
		// 		i += get_var_len(str + i);
		// 	}
		// }
	}
	exp[j] = '\0';
	free(str);
	return (exp);
}
