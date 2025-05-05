/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:00:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/05/05 15:10:14 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_pid;

void	ft_init_data(t_data *data, char **env)
{
	data->prompt = NULL;
	data->env = ft_env(env);
	if (data->env == NULL)
	{
		perror("ft_env");
		exit(EXIT_FAILURE);
	}
	data->exit_status = 0;
}

void	ft_free(t_data *data)
{
	if (data->prompt)
		free(data->prompt);
	if (data->env)
		ft_freetab(data->env);
}

int	main(int ac, char **av, char **env)
{
	t_data data;

	(void)ac;
	(void)av;
	g_pid = 0;
	ft_memset(&data, 0, sizeof(t_data));
	ft_init_data(&data, env);
	// int i = 0;
	// while (data.env[i])
	// {
	// 	printf("%s%s\n", "\033[0;31m", env[i]);
	// 	printf("%s%s\n", "\033[0;32m", data.env[i]);
	// 	i++;
	// }
	// printf("%s", "\033[0m");
	ft_free(&data);
	return (0);
}