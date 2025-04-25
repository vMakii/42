/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:00:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/25 10:13:07 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t		g_pid;

static char	**ft_env(char **envp)
{
	int		len;
	char	**env;

	len = ft_strlen(envp);
	env = malloc(sizeof(char *) * len);
	if (!env)
		return (NULL);
	return (env);
}

void	ft_init_data(t_data *data, int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
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
	free(data);
}

int	main(int ac, char **av, char **env)
{
	t_data data;

	ft_memset(&data, 0, sizeof(t_data));
	ft_init_data(&data, ac, av, env);
	ft_free(&data);
	return (0);
}