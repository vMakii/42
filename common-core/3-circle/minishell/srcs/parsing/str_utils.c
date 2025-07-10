/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:23:45 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/10 13:11:42 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ft_isredir(char *str, int *i)
{
	if (str[*i] == '<' || str[*i] == '>')
	{
		if (str[*i + 1] == '<' || str[*i + 1] == '>')
		{
			(*i)++;
			(*i)++;
			return (true);
		}
	}
	if (str[*i] == '<' || str[*i] == '>')
	{
		(*i)++;
		return (true);
	}
	return (false);
}

static void	ft_cutword_utils(char *str, int *i, int *end)
{
	char	quote;

	if (ft_isredir(str, i))
	{
		while (str[*i] && ft_isspace(str[*i]))
			(*i)++;
	}
	while (str[*i] && !ft_isspace(str[*i]) && str[*i] != '|' && str[*i] != '<'
		&& str[*i] != '>')
	{
		if (str[*i] == '\'' || str[*i] == '"')
		{
			quote = str[*i];
			(*i)++;
			while (str[*i] && str[*i] != quote)
				(*i)++;
			if (str[*i] == quote)
				(*i)++;
		}
		else
			(*i)++;
	}
	*end = *i;
}

void	ft_cutword(char *str, int *i, int *start, int *end)
{
	*start = *i;
	if (ft_isspace(str[*i]))
	{
		(*i)++;
		while (str[*i] && ft_isspace(str[*i]))
			(*i)++;
		*end = *i;
	}
	else if (str[*i] == '|')
	{
		(*i)++;
		*end = *i;
	}
	else
	{
		ft_cutword_utils(str, i, end);
	}
}

char	*ft_optimize(char *str)
{
	int		i;
	int		start;
	int		end;
	char	*tmp;

	i = 0;
	start = 0;
	if (str[i] == ' ' || str[i] == '|')
		end = 1;
	else if (ft_isredir(str, &i))
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		start = i;
		end = ft_strlen(str);
	}
	else
		end = ft_strlen(str);
	tmp = ft_substr(str, start, end - start);
	free(str);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*ft_strtrim_quote(char *str)
{
	int		i;
	int		j;
	int		quote;
	char	*cpy;

	i = 0;
	j = 0;
	cpy = malloc(ft_strlen(str) + 1);
	if (!cpy)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				cpy[j++] = str[i++];
			i++;
		}
		else
			cpy[j++] = str[i++];
	}
	cpy[j] = '\0';
	free(str);
	return (cpy);
}
