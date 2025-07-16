/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:22:53 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/16 12:26:41 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_printerr(char *msg)
{
	if (msg)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		if (errno)
		{
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putstr_fd(strerror(errno), STDERR_FILENO);
		}
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}
