/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:08:41 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/10 13:05:21 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_check_redir_utils(const char *str, int i)
{
	if ((str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<')
		|| (str[i] == '>' && str[i + 1] == '>' && str[i + 2] == '>'))
	{
		if (str[i] == '<')
			return (ft_print_error("syntax error near unexpected token `<'"),
				false);
		else
			return (ft_print_error("syntax error near unexpected token `>'"),
				false);
	}
	if ((str[i] == '>' || str[i] == '<'))
	{
		if (str[i + 1] == '|')
			return (ft_print_error("syntax error near unexpected token `|'"),
				false);
	}
	if (str[i] == '<' && str[i + 1] == '>')
		return (ft_print_error("syntax error ambiguous redirection"), false);
	if (str[i] == '|' && str[i + 1] == '|')
		return (ft_print_error("syntax error near unexpected token `||'"),
			false);
	return (true);
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

static void	ft_expand_var(t_data *data, char *str, t_expand *expand)
{
	int		k;
	char	*env_value;
	int		var_len;

	env_value = get_env_value(data->env, str + expand->i);
	var_len = ft_strlen(env_value);
	if (var_len > 0)
	{
		k = 0;
		while (env_value[k])
			expand->exp[(expand->j)++] = env_value[k++];
	}
	expand->i += get_var_len(str + expand->i);
}

static void	ft_expand_loop(t_data *data, char *str, t_expand *expand)
{
	int		k;
	char	*env_value;

	expand->i++;
	if (str[expand->i] == '\0' || str[expand->i] == ' '
		|| str[expand->i] == '"')
		expand->exp[(expand->j)++] = '$';
	else if (ft_strncmp(str + expand->i, "?", 1) == 0)
	{
		env_value = ft_itoa(data->exit_status);
		k = 0;
		while (env_value[k])
			expand->exp[(expand->j)++] = env_value[k++];
		(expand->i)++;
		free(env_value);
	}
	else
	{
		ft_expand_var(data, str, expand);
	}
}

char	*ft_expand(t_data *data, char *str)
{
	t_expand	expand;

	ft_memset(&expand, 0, sizeof(t_expand));
	expand.len = ft_expand_len(data, str);
	expand.exp = malloc(expand.len + 1);
	if (!expand.exp)
		return (NULL);
	while (str[expand.i])
	{
		if (str[expand.i] == '"')
			expand.in_dbl = !expand.in_dbl;
		if (str[expand.i] == '\'' && !expand.in_dbl)
			expand.in_sgl = !expand.in_sgl;
		if (str[expand.i] == '$' && !expand.in_sgl)
		{
			ft_expand_loop(data, str, &expand);
		}
		else
			expand.exp[expand.j++] = str[expand.i++];
	}
	expand.exp[expand.j] = '\0';
	free(str);
	return (expand.exp);
}
