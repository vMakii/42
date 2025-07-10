/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:04:42 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/10 10:01:32 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ft_check_quotes(const char *str)
{
	int	i;
	int	in_sgl;
	int	in_dbl;

	i = 0;
	in_sgl = 0;
	in_dbl = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !in_dbl)
			in_sgl = !in_sgl;
		else if (str[i] == '"' && !in_sgl)
			in_dbl = !in_dbl;
		i++;
	}
	if (in_sgl || in_dbl)
		return (ft_print_error("syntax error unmatched quotes"), false);
	return (true);
}

static bool	ft_checklast(const char *str)
{
	int		i;
	char	c;

	i = 0;
	c = '\0';
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			c = str[i];
		i++;
	}
	if (c == '>' || c == '<' || c == '|')
		return (ft_print_error("syntax error near unexpected token `newline'"),
			false);
	return (true);
}

static bool	ft_check_redir(const char *str)
{
	int	i;
	int	quote;

	i = -1;
	quote = 0;
	while (str[++i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			quote = str[i];
			while (str[++i] && str[i] != quote)
			{
				if (str[i] == '"' || str[i] == '\'')
					if (quote == str[i])
						quote = 0;
			}
		}
		if (quote == 0)
		{
			if (!ft_check_redir_utils(str, i))
				return (false);
		}
	}
	return (true);
}

static bool	ft_check_pipe(const char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '|')
		return (ft_print_error("syntax error near unexpected token '|'"),
			false);
	return (true);
}

bool	ft_parse(t_data *data)
{
	int	i;
	int	start;
	int	end;

	i = -1;
	start = -1;
	end = -1;
	if (!ft_check_quotes(data->prompt) || !ft_checklast(data->prompt)
		|| !ft_check_redir(data->prompt) || !ft_check_pipe(data->prompt))
	{
		data->exit_status = 2;
		return (false);
	}
	while (data->prompt[++i])
	{
		ft_cutword(data->prompt, &i, &start, &end);
		i = end - 1;
		if (!ft_tokenize(data, start, end))
		{
			ft_print_error("tokenizator failed");
			data->exit_status = 2;
			return (false);
		}
	}
	return (true);
}
