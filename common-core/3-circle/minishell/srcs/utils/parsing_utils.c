/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:36:47 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/17 14:47:46 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ft_check_redir_utils2(const char *str, int i)
{
	if (str[i] == '<')
	{
		i++;
		if (str[i + 1] == '<')
			i++;
		while (ft_isspace(str[++i]))
			;
		if (str[i] == '\0' || str[i] == '|' || str[i] == '>' || str[i] == '<')
			return (ft_print_error("syntax error near unexpected token `<' or `<<'"),
				false);
	}
	else if (str[i] == '>')
	{
		i++;
		if (str[i + 1] == '>')
			i++;
		while (ft_isspace(str[++i]))
			;
		if (str[i] == '\0' || str[i] == '|' || str[i] == '>' || str[i] == '<')
			return (ft_print_error("syntax error near unexpected token `>' or `>>'"),
				false);
	}
	return (true);
}

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
	if (!ft_check_redir_utils2(str, i))
		return (false);
	return (true);
}
