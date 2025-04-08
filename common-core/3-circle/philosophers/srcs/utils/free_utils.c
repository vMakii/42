/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:37:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/08 16:05:07 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(char *str)
{
	printf("Error: %s\n", str);
	return ;
}

void	ft_free(t_data *data)
{
	free(data->dead_lock);
	free(data->print_lock);
	free(data->philos);
	free(data->forks);
}