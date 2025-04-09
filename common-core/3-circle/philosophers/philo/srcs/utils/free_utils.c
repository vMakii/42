/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:37:59 by mivogel           #+#    #+#             */
/*   Updated: 2025/04/09 13:54:46 by mivogel          ###   ########.fr       */
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
	free(data->philos);
	free(data->forks);
}
