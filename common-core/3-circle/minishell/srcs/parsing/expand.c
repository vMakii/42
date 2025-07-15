/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:08:41 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/15 22:34:40 by mivogel          ###   ########.fr       */
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

static int	ft_get_exit_status_len(int exit_status)
{
	char	*temp;
	int		len;

	temp = ft_itoa(exit_status);
	if (!temp)
		return (0);
	len = ft_strlen(temp);
	free(temp);
	return (len);
}

// static void	ft_process_quotes(const char *str, t_expand *params)
// {
// 	if (str[params->i] == '"')
// 	{
// 		params->in_dbl = !params->in_dbl;
// 		(params->len)++;
// 		(params->i)++;
// 	}
// 	else if (str[params->i] == '\'' && !params->in_dbl)
// 	{
// 		params->in_sgl = !params->in_sgl;
// 		(params->len)++;
// 		(params->i)++;
// 	}
// }

static void	ft_process_dollar_exit(t_data *data, const char *str,
		t_expand *params)
{
	if (str[params->i + 1] == '?')
	{
		params->len += ft_get_exit_status_len(data->exit_status);
		params->i += 2;
	}
	else if (str[params->i + 1] == '\0' || str[params->i + 1] == ' '
		|| str[params->i + 1] == '"')
	{
		(params->len)++;
		(params->i)++;
	}
	else
	{
		params->len += ft_strlen(get_env_value(data->env, str + params->i + 1));
		params->i += get_var_len(str + params->i + 1) + 1;
	}
}

// static void	ft_process_dollar_edge(const char *str, t_expand *params)
// {
// 	if (str[params->i + 1] == '\0' || str[params->i + 1] == ' ' || str[params->i
// 		+ 1] == '"')
// 	{
// 		(params->len)++;
// 		(params->i)++;
// 	}
// }

// static void	ft_process_dollar_var(t_data *data, const char *str,
// 		t_expand *params)
// {
// 	params->len += ft_strlen(get_env_value(data->env, str + params->i + 1));
// 	params->i += get_var_len(str + params->i + 1) + 1;
// }

static void	ft_expand_len_loop(t_data *data, const char *str, t_expand *params)
{
	if (str[params->i] == '"' || (str[params->i] == '\'' && !params->in_dbl))
	{
		if (str[params->i] == '"')
		{
			params->in_dbl = !params->in_dbl;
			(params->len)++;
			(params->i)++;
		}
		else if (str[params->i] == '\'' && !params->in_dbl)
		{
			params->in_sgl = !params->in_sgl;
			(params->len)++;
			(params->i)++;
		}
	}
	else if (str[params->i] == '$' && !params->in_sgl)
		ft_process_dollar_exit(data, str, params);
	else
	{
		(params->len)++;
		(params->i)++;
	}
}

static int	ft_expand_len(t_data *data, const char *str)
{
	t_expand	params;

	ft_memset(&params, 0, sizeof(t_expand));
	while (str[params.i])
		ft_expand_len_loop(data, str, &params);
	return (params.len);
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
		while (env_value[k] && expand->j < expand->len)
			expand->exp[(expand->j)++] = env_value[k++];
	}
	expand->i += get_var_len(str + expand->i);
}

static void	ft_expand_loop(t_data *data, char *str, t_expand *expand)
{
	int		k;
	char	*env_value;

	expand->i++;
	if (str[expand->i] == '\0' || str[expand->i] == ' ')
	{
		if (expand->j < expand->len)
			expand->exp[(expand->j)++] = '$';
	}
	else if (ft_strncmp(str + expand->i, "?", 1) == 0)
	{
		env_value = ft_itoa(data->exit_status);
		k = 0;
		while (env_value[k] && expand->j < expand->len)
			expand->exp[(expand->j)++] = env_value[k++];
		(expand->i)++;
		free(env_value);
	}
	else
	{
		ft_expand_var(data, str, expand);
	}
}

static t_expand	*ft_init_expand(t_data *data, char *str)
{
	t_expand	*expand;

	expand = malloc(sizeof(t_expand));
	if (!expand)
		return (NULL);
	ft_memset(expand, 0, sizeof(t_expand));
	expand->len = ft_expand_len(data, str);
	expand->exp = malloc(expand->len + 1);
	if (!expand->exp)
	{
		free(expand);
		return (NULL);
	}
	return (expand);
}

static void	ft_process_char(char *str, t_expand *expand)
{
	if (str[expand->i] == '"')
		expand->in_dbl = !expand->in_dbl;
	if (str[expand->i] == '\'' && !expand->in_dbl)
		expand->in_sgl = !expand->in_sgl;
	if (expand->j < expand->len)
		expand->exp[expand->j++] = str[expand->i++];
	else
		expand->i++;
}

char	*ft_expand(t_data *data, char *str)
{
	t_expand	*expand;
	char		*result;

	expand = ft_init_expand(data, str);
	if (!expand)
	{
		free(str);
		return (NULL);
	}
	while (str[expand->i])
	{
		if (str[expand->i] == '$' && !expand->in_sgl)
			ft_expand_loop(data, str, expand);
		else
			ft_process_char(str, expand);
	}
	expand->exp[expand->j] = '\0';
	result = expand->exp;
	free(expand);
	free(str);
	return (result);
}
