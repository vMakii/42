/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:13:27 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/07 13:25:12 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_getcmd(t_data *data, t_tokens type)
{
	t_cmd	*tmp;

	if (data->cmd)
	{
		tmp = data->cmd;
		if (tmp->type == type)
			return (tmp);
		while (tmp)
		{
			if (tmp->type == type)
				return (tmp);
			if (tmp->type == PIPE)
				return (NULL);
			tmp = tmp->next;
		}
	}
	return (NULL);
}

static bool	ft_isbuiltin(char *str)
{
	if (ft_strncmp(str, "cd", 2) == 0 || ft_strncmp(str, "echo", 4) == 0
		|| ft_strncmp(str, "env", 3) == 0 || ft_strncmp(str, "exit", 4) == 0
		|| ft_strncmp(str, "export", 6) == 0 || ft_strncmp(str, "pwd", 3) == 0
		|| ft_strncmp(str, "unset", 5) == 0)
		return (true);
	return (false);
}

static t_tokens	ft_tokenizator(t_data *data, char *str)
{
	static int	pipe = 0;

	if (ft_strncmp(str, "<<", 2) == 0)
		return (HEREDOC);
	else if (ft_strncmp(str, "<", 1) == 0)
		return (IN);
	else if (ft_strncmp(str, ">>", 2) == 0)
		return (APPEND);
	else if (ft_strncmp(str, ">", 1) == 0)
		return (OUT);
	else if (ft_strncmp(str, " ", 1) == 0 || ft_strncmp(str, "\t", 1) == 0)
		return (SPC);
	else if (ft_strncmp(str, "|", 1) == 0)
	{
		pipe = 1;
		return (PIPE);
	}
	else if ((!ft_getcmd(data, CMD) && !ft_getcmd(data, BUILTIN)) || pipe == 1)
	{
		pipe = 0;
		return (CMD);
	}
	return (ARG);
}

static char	*ft_str_n_tokens(t_tokens *type, t_data *data, int start, int end)
{
	char	*str;

	*type = ft_tokenizator(data, data->prompt + start);
	str = ft_optimize(ft_substr(data->prompt, start, end - start));
	if (!str)
		return (NULL);
	if (*type != HEREDOC)
	{
		str = ft_expand(data, str);
		if (!str)
			return (NULL);
	}
	str = ft_strtrim_quote(str);
	if (!str)
		return (NULL);
	if (*type == CMD && ft_isbuiltin(str))
		*type = BUILTIN;
	return (str);
}

bool	ft_tokenize(t_data *data, int start, int end)
{
	char		*str;
	t_tokens	type;
	t_cmd		*new;

	str = ft_str_n_tokens(&type, data, start, end);
	if (!str)
		return (false);
	if (!data->cmd)
	{
		data->cmd = ft_lstnew(str, type);
		if (!data->cmd)
			return (false);
	}
	else
	{
		new = ft_lstnew(str, type);
		if (!new)
			return (false);
		ft_lstadd_back(&data->cmd, new);
	}
	return (true);
}
