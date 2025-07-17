/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:45:01 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/17 14:46:08 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	ft_process(t_data *data, const char *str, t_expand *params)
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
		ft_process(data, str, params);
	else
	{
		(params->len)++;
		(params->i)++;
	}
}

int	ft_expand_len(t_data *data, const char *str)
{
	t_expand	params;

	ft_memset(&params, 0, sizeof(t_expand));
	while (str[params.i])
		ft_expand_len_loop(data, str, &params);
	return (params.len);
}
