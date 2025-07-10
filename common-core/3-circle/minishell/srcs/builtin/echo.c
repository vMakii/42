/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:35:20 by salsoysa          #+#    #+#             */
/*   Updated: 2025/07/09 21:56:16 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_for_opt(char *arg)
{
	int	i;

	i = 1;
	if (!arg || arg[0] != '-' || arg[1] == '\0')
		return (false);
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

int	ft_echo(char **args)
{
	int	i;
	int	opt_n;

	i = 1;
	opt_n = 0;
	while (args[i] && check_for_opt(args[i]))
	{
		opt_n = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1] && args[i][0] != '\0')
			write(1, " ", 1);
		i++;
	}
	if (opt_n == 0)
		write(1, "\n", 1);
	return (0);
}
