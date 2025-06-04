/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:04:42 by mivogel           #+#    #+#             */
/*   Updated: 2025/06/04 14:10:50 by mivogel          ###   ########.fr       */
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
	{
		printf("minishell: error: unmatched quotes\n");
		return (false);
	}
	return (true);
}

static bool	ft_checklast(const char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			c = str[i];
		i++;
	}
	if (c == '|' || c == '<' || c == '>')
	{
		printf("minishell: error: unexpected token '%c'\n", c);
		return (false);
	}
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
	if (!ft_check_quotes(data->prompt) || !ft_checklast(data->prompt))
		return (false);
	while (data->prompt[++i])
	{
		ft_cutword(data->prompt, &i, &start, &end);
		i = end - 1;
		if (!ft_tokenize(data, start, end))
		{
			printf("minishell: error: tokenizator failed\n");
			return (false);
		}
	}
	return (true);
}
