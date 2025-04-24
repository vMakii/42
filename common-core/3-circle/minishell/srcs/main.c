/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:00:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/24 18:39:52 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_data(t_data *data, int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	data->prompt = NULL;
	data->env = ft_env(data, env);
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